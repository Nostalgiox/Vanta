#include "vanta/steam/SteamScanner.hpp"
#include "vanta/steam/VdfParser.hpp"

#include <cstdlib>
#include <fstream>
#include <set>
#include <stdexcept>

namespace vanta::steam
{

    namespace
    {

        std::string readFile(const std::filesystem::path &path)
        {
            std::ifstream file(path);

            if (!file.is_open())
            {
                throw std::runtime_error("Cannot open file: " + path.string());
            }

            return {
                std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>()};
        }

        std::string getValue(const VdfNode &node, const std::string &key)
        {
            const VdfNode *child = node.get(key);

            return child ? child->value : "";
        }

        std::filesystem::path normalizePath(
            const std::filesystem::path &path)
        {
            std::error_code error;
            auto result = std::filesystem::weakly_canonical(path, error);

            return error ? path.lexically_normal() : result;
        }

    }

    SteamScanner::SteamScanner() = default;

    bool SteamScanner::detectSteam()
    {
        steamPath.clear();

#ifdef _WIN32
        const char *programFiles = std::getenv("PROGRAMFILES(X86)");

        if (programFiles)
        {
            const auto candidate =
                std::filesystem::path(programFiles) / "Steam";

            if (std::filesystem::exists(candidate / "steam.exe"))
            {
                steamPath = normalizePath(candidate);
                return true;
            }
        }

        return false;

#elif __linux__
        const char *home = std::getenv("HOME");

        if (!home)
        {
            return false;
        }

        const std::filesystem::path homePath(home);

        const std::vector<std::filesystem::path> candidates = {
            homePath / ".local/share/Steam",
            homePath / ".steam/steam",
            homePath / ".steam/root",
            homePath / ".var/app/com.valvesoftware.Steam/.local/share/Steam"};

        for (const auto &candidate : candidates)
        {
            if (std::filesystem::exists(
                    candidate / "steamapps/libraryfolders.vdf"))
            {
                steamPath = normalizePath(candidate);
                return true;
            }
        }

        return false;
#else
        return false;
#endif
    }

    const std::filesystem::path &SteamScanner::getSteamPath() const
    {
        return steamPath;
    }

    std::vector<std::filesystem::path> SteamScanner::findLibraries() const
    {
        std::vector<std::filesystem::path> libraries;
        std::set<std::filesystem::path> uniqueLibraries;

        if (steamPath.empty())
        {
            return libraries;
        }

        const auto configPath =
            steamPath / "steamapps/libraryfolders.vdf";

        if (!std::filesystem::exists(configPath))
        {
            return libraries;
        }

        const auto root = VdfParser::parse(readFile(configPath));
        const VdfNode *libraryFolders = root.get("libraryfolders");

        if (!libraryFolders)
        {
            return libraries;
        }

        for (const auto &[key, node] : libraryFolders->children)
        {
            (void)key;

            const std::string path = getValue(node, "path");

            if (path.empty())
            {
                continue;
            }

            const auto libraryPath = normalizePath(path);
            const auto steamApps = libraryPath / "steamapps";

            if (std::filesystem::is_directory(steamApps) &&
                uniqueLibraries.insert(libraryPath).second)
            {
                libraries.push_back(libraryPath);
            }
        }

        // Fallback to the main Steam library if it wasn't listed.
        const auto mainLibrary = normalizePath(steamPath);

        if (std::filesystem::is_directory(mainLibrary / "steamapps") &&
            uniqueLibraries.insert(mainLibrary).second)
        {
            libraries.push_back(mainLibrary);
        }

        return libraries;
    }

    std::vector<InstalledGame> SteamScanner::scanLibrary(
        const std::filesystem::path &libraryPath) const
    {
        std::vector<InstalledGame> games;

        const auto steamApps = libraryPath / "steamapps";

        if (!std::filesystem::is_directory(steamApps))
        {
            return games;
        }

        for (const auto &entry :
             std::filesystem::directory_iterator(steamApps))
        {
            if (!entry.is_regular_file())
            {
                continue;
            }

            const auto filename = entry.path().filename().string();

            if (filename.rfind("appmanifest_", 0) != 0 ||
                entry.path().extension() != ".acf")
            {
                continue;
            }

            try
            {
                const auto root = VdfParser::parse(readFile(entry.path()));
                const VdfNode *appState = root.get("AppState");

                if (!appState)
                {
                    continue;
                }

                const std::string appId = getValue(*appState, "appid");
                const std::string name = getValue(*appState, "name");
                const std::string installDirectory =
                    getValue(*appState, "installdir");

                if (appId.empty() || name.empty() ||
                    installDirectory.empty())
                {
                    continue;
                }

                const auto installPath =
                    steamApps / "common" / installDirectory;

                // A manifest alone does not guarantee the game is installed.
                if (!std::filesystem::is_directory(installPath))
                {
                    continue;
                }

                games.push_back({appId,
                                 name,
                                 installDirectory,
                                 libraryPath,
                                 normalizePath(installPath)});
            }
            catch (const std::exception &)
            {
                // Skip invalid manifests without stopping the entire scan.
                continue;
            }
        }

        return games;
    }

    std::vector<InstalledGame> SteamScanner::scanGames()
    {
        std::vector<InstalledGame> games;

        if (steamPath.empty() && !detectSteam())
        {
            return games;
        }

        for (const auto &library : findLibraries())
        {
            auto libraryGames = scanLibrary(library);

            for (auto &game : libraryGames)
            {
                games.push_back(std::move(game));
            }
        }

        return games;
    }

}