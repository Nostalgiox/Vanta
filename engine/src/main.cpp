
#include <iostream>
#include <string>

#ifdef _WIN32
    #define VANTA_PLATFORM "windows"
#elif __linux__
    #define VANTA_PLATFORM "linux"
#else
    #define VANTA_PLATFORM "unknown"
#endif

int main() {
    std::string input;

    std::cout << R"({"event":"engine_ready","platform":")"
              << VANTA_PLATFORM
              << R"(","version":"0.1.0"})"
              << std::endl;

    while (std::getline(std::cin, input)) {
        if (input == "ping") {
            std::cout << R"({"status":"ok","message":"pong"})"
                      << std::endl;
        }
        else if (input == "info") {
            std::cout << R"({"platform":")"
                      << VANTA_PLATFORM
                      << R"(","version":"0.1.0"})"
                      << std::endl;
        }
        else if (input == "exit") {
            std::cout << R"({"status":"ok","message":"shutdown"})"
                      << std::endl;
            break;
        }
        else {
            std::cout << R"({"status":"error","message":"unknown_command"})"
                      << std::endl;
        }
    }

    return 0;
}
