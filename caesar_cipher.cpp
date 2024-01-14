// Fun CLI program that encrypts or decrypts a file using the famous Caesar cipher.

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

// ====================== //
// ====== UTILITIES ===== //
// ====================== //

// ANSI escape code for red text
const std::string red("\033[0;31m");

// ANSI escape code to reset text color back to normal
const std::string reset("\033[0m");


bool isInteger(const std::string &str)
{
    for (char ch : str)
    {
        if (!std::isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

int getValidChoice() {
    std::string choiceStr;
    int choice;

    do
    {
        std::cout << "Enter your choice: ";
        std::cin >> choiceStr;

        if (!isInteger(choiceStr))
        {
            std::cerr << red << "Error: Invalid input. Please enter a valid integer choice." << reset << std::endl;
            continue;
        }

        choice = std::stoi(choiceStr);

        if (choice != 1 && choice != 2)
        {
            std::cerr << red << "Error: Invalid input. Please enter 1 or 2." << reset << std::endl;
        }

    } while (choice != 1 && choice != 2);

    return choice;
}

int getValidKey()
{
    std::string keyStr;
    int key;

    do
    {
        std::cout << "Enter key (integer): ";
        std::cin >> keyStr;

        if (!isInteger(keyStr))
        {
            std::cerr << red <<"Error: Invalid input. Please enter a valid integer key." << reset << std::endl;
            continue;
        }

        key = std::stoi(keyStr);

        if (key < 0 || key > 255)
        {
            std::cerr << red << "Error: Key must be between 0 and 255." << reset << std::endl;
        }

    } while (key < 0 || key > 255 || !isInteger(keyStr));

    return key;
}

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
    int choice = getValidChoice();
    int key = getValidKey();

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
