#include <fstream>
#include <filesystem>
#include "../../include/utils/caesar.h"

namespace fs = std::filesystem;

void caesar::encryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key)
{
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch + key);
    }

    inputFile.close();
    outputFile.close();
}

void caesar::decryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key)
{
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch - key);
    }

    inputFile.close();
    outputFile.close();
}
