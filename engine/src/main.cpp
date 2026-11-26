
#include <iostream>
#include <string>
#include "vanta/steam/SteamScanner.hpp"

#ifdef _WIN32
#define VANTA_PLATFORM "windows"
#elif __linux__
#define VANTA_PLATFORM "linux"
#else
#define VANTA_PLATFORM "unknown"
#endif

int main()
{
    std::string input;

    std::cout << R"({"event":"engine_ready","platform":")"
              << VANTA_PLATFORM
              << R"(","version":"0.1.0"})"
              << std::endl;

    while (std::getline(std::cin, input))
    {
        if (input == "ping")
        {
            std::cout << R"({"status":"ok","message":"pong"})"
                      << std::endl;
        }
        else if (input == "info")
        {
            std::cout << R"({"platform":")"
                      << VANTA_PLATFORM
                      << R"(","version":"0.1.0"})"
                      << std::endl;
        }
        else if (input == "exit")
        {
            std::cout << R"({"status":"ok","message":"shutdown"})"
                      << std::endl;
            break;
        }
        else if (input == "scan")
        {
            vanta::steam::SteamScanner scanner;

            if (!scanner.detectSteam())
            {
                std::cout << "Steam not found." << std::endl;
                continue;
            }

            std::cout << "Steam found: "
                      << scanner.getSteamPath()
                      << std::endl;

            const auto games = scanner.scanGames();

            std::cout << "Installed games: "
                      << games.size()
                      << std::endl;

            for (const auto &game : games)
            {
                std::cout << "--------------------------------\n";
                std::cout << "Name: " << game.name << '\n';
                std::cout << "App ID: " << game.appId << '\n';
                std::cout << "Install directory: "
                          << game.installPath << '\n';
            }

            std::cout << std::flush;
        }
        else
        {
            std::cout << R"({"status":"error","message":"unknown_command"})"
                      << std::endl;
        }
    }

    return 0;
}
