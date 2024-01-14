// Fun CLI program that encrypts or decrypts a file using the famous Caesar cipher.

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "utils/utils.cpp"


namespace fs = std::filesystem;

// ====================== //
// ====== FUNCTIONS ===== //
// ====================== //

void encryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key)
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

void decryptFile(const fs::path &inputFilePath, const fs::path &outputFilePath, int key)
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

// ====================== //
// ====== MAIN CODE ===== //
// ====================== //

int main()
{
    std::string inputFilePathStr, outputFilePathStr;
    
    // Get user inputs
    int choice = utils::getValidChoice();
    int key = utils::getValidKey();

    std::cout << "Enter input file path: ";
    std::cin >> inputFilePathStr;
    std::cout << "Enter output file path: ";
    std::cin >> outputFilePathStr;

    // Convert input file paths to fs::path objects
    fs::path inputFilePath(inputFilePathStr);
    fs::path outputFilePath(outputFilePathStr);

    if (choice == 1)
    {
        encryptFile(inputFilePath, outputFilePath, key);
    }
    else if (choice == 2)
    {
        decryptFile(inputFilePath, outputFilePath, key);
    }

    return 0;
}
