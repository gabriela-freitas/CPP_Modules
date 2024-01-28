#pragma once
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Function to print a colored string in red
void printRed(const std::string &text);

// Function to print a colored string in green
void printGreen(const std::string &text);

// Function to print a colored string in yellow
void printYellow(const std::string &text);

// Function to print a colored string in blue
void printBlue(const std::string &text);

// Function to print a colored string in gray
void printGray(const std::string &text);

// Function to seed a container with some random numbers
template <typename Container>
Container &seedContainerRandomNumbers(Container &container, size_t n)
{
    // std::srand(std::time(0));
    for (size_t i = 0; i < n; i++)
    {
        int RandNumber = (std::rand() % (n * 100)) + 1;
        container.push_back(RandNumber);
    }
    return container;
}

// Function to send the Container content to stringStream
template <typename Container>
std::stringstream containerTosStream(Container &container)
{
    typedef typename Container::iterator iterator;
    std::stringstream sstream;

    for (iterator it = container.begin(); it != container.end(); it++)
    {
        sstream << *it << " ";
    }
    return sstream;
}

// Function to copy the content of one container to another
template <typename Container1, typename Container2>
void seedSecondContainer(Container1 &source, Container2 &dest)
{
    typedef typename Container1::iterator iterator;

    for (iterator it = source.begin(); it != source.end(); it++)
    {
        dest.push_back(*it);
    }
}