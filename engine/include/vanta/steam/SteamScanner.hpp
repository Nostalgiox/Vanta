#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace vanta::steam
{

    struct InstalledGame
    {
        std::string appId;
        std::string name;
        std::string installDirectory;
        std::filesystem::path libraryPath;
        std::filesystem::path installPath;
    };

    class SteamScanner
    {
    public:
        SteamScanner();

        bool detectSteam();

        std::vector<InstalledGame> scanGames();

        const std::filesystem::path &getSteamPath() const;

    private:
        std::filesystem::path steamPath;

        std::vector<std::filesystem::path> findLibraries() const;

        std::vector<InstalledGame> scanLibrary(
            const std::filesystem::path &libraryPath) const;
    };

}