// Fun CLI program that encrypts or decrypts a file using the famous Caesar cipher.

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "../include/utils/utils.h"
#include "../include/utils/caesar.h"

namespace fs = std::filesystem;

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
        caesar::encryptFile(inputFilePath, outputFilePath, key);
    }
    else if (choice == 2)
    {
        caesar::decryptFile(inputFilePath, outputFilePath, key);
    }

    return 0;
}
