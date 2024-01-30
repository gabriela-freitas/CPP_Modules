#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <deque>
#include <list>
#include "testingUtils.hpp"
#include <string>

template <typename T>
void test(T &container, std::string type)
{
    seedContainerRandomNumbers(container, 10);
    int RandNumber = (std::rand() % (10 * 2));

    std::stringstream ss;
    ss << type << ": [";
    ss << containerToStr(container) << "]";
    printGray(ss.str());
    ss.str("");
    ss.clear();
    ss << "Looking for a random Number: " << RandNumber << std::endl;

    ss << "Found? ";
    printYellow(ss.str());
    ss.str("");
    ss.clear();

    if (easyfind(container, RandNumber) != container.end())
        printGreen("Yes!");
    else
        printRed("No :(");

    ss << "Looking for a existing number: " << *(container.begin()) << std::endl;

    ss << "Found? ";
    printYellow(ss.str());
    ss.str("");
    ss.clear();

    if (easyfind(container, *(container.begin())) != container.end())
        printGreen("Yes!");
    else
        printRed("Something's off....");
    
    std::cout << std::endl;
}

int main(void)
{
    std::srand(std::time(0));
    std::vector<int> ve;
    std::deque<int> de;
    std::list<int> lt;

    printBlue("Testing with different types of sequential containers:");
    std::cout << std::endl;
    test(ve, "Vector");
    test(de, "Deque");
    test(lt, "List");
    return (0);
}
