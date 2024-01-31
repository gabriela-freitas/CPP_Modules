#include "testingUtils.hpp"
#include <iostream>

// Function to print a colored string in red
void printRed(const std::string& text) {
    std::cout << "\033[1;31m" << text << "\033[0m" << std::endl;
}

// Function to print a colored string in green
void printGreen(const std::string& text) {
    std::cout << "\033[1;32m" << text << "\033[0m" << std::endl;
}

// Function to print a colored string in yellow
void printYellow(const std::string& text) {
    std::cout << "\033[1;33m" << text << "\033[0m" << std::endl;
}

// Function to print a colored string in blue
void printBlue(const std::string& text) {
    std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;
}

void printGray(const std::string &text)
{
    std::cout << "\033[1;40m" << text << "\033[0m" << std::endl;
}