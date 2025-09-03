#pragma once
#include <filesystem>
#include <fstream>
#include <cstdlib>  

inline std::filesystem::path GetAppDataPath() {
    char* buffer = nullptr;
    size_t len = 0;

    if (_dupenv_s(&buffer, &len, "LOCALAPPDATA") == 0 && buffer) {
        std::filesystem::path p(buffer);
        free(buffer);
        return p / "Mechanism";
    }

    return {};
}

inline void SaveLastOpenedPath(const std::string& fullPath) {
    try {
        std::filesystem::path dir = GetAppDataPath();
        if (dir.empty()) return;

        std::filesystem::create_directories(dir);
        std::ofstream out(dir / "lastpath.txt", std::ios::trunc);
        if (out.is_open()) {
            out << fullPath;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to save last path: " << e.what() << std::endl;
    }
}

inline std::string LoadLastOpenedPath() {
    try {
        std::filesystem::path dir = GetAppDataPath();
        if (dir.empty()) return {};

        std::ifstream in(dir / "lastpath.txt");
        if (in.is_open()) {
            std::string path;
            std::getline(in, path);
            return path;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to load last path: " << e.what() << std::endl;
    }
    return {};
}