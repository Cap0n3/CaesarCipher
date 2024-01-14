#include <iostream>
#include <fstream>
#include <string>
#include "../../include/utils/utils.h"

// ANSI escape code for red text
const std::string red("\033[0;31m");

// ANSI escape code to reset text color back to normal
const std::string reset("\033[0m");

// ====================== //
// ====== UTILITIES ===== //
// ====================== //


bool utils::isInteger(const std::string &str)
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

int utils::getValidKey()
{
    std::string keyStr;
    int key;

    do
    {
        std::cout << "Enter key (integer): ";
        std::cin >> keyStr;

        if (!utils::isInteger(keyStr))
        {
            std::cerr << red <<"Error: Invalid input. Please enter a valid integer key." << reset << std::endl;
            continue;
        }

        key = std::stoi(keyStr);

        if (key < 0 || key > 255)
        {
            std::cerr << red << "Error: Key must be between 0 and 255." << reset << std::endl;
        }

    } while (key < 0 || key > 255 || !utils::isInteger(keyStr));

    return key;
}

int utils::getValidChoice() {
    std::string choiceStr;
    int choice;

    do
    {
        std::cout << "Enter your choice: ";
        std::cin >> choiceStr;

        if (!utils::isInteger(choiceStr))
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