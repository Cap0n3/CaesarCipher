#pragma once
#include <filesystem>

namespace fs = std::filesystem;

namespace caesar {
    extern void encryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key);
    extern void decryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key);
}