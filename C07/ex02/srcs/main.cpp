#include <iostream>
#include "Array.hpp"
#include "iter.hpp"

#define MAX_VAL 40

int returnRand(int i)
{
    return std::rand() % MAX_VAL + i;
}

//TODO: this file was in the subject
int main(int, char**)
{
	std::cout << "\033[1;34mTesting in a int array: \033[0m" << std::endl;

    Array<int> intArr(std::rand() % MAX_VAL);
	std::srand(std::time(0));
    iter(&intArr[0], intArr.size(), &returnRand);

    Array<int> otherArr(intArr);
    otherArr[intArr.size() % 2] = intArr[intArr.size() % 2] * 2;

	std::cout << "\033[1;34mMaking sure copied Array is independent in index (" << intArr.size() % 2 << "): \033[0m" << std::endl;
    std::cout << "First Array = " << intArr[intArr.size() % 2] << std::endl;
    std::cout << "Copied Array = " << otherArr[intArr.size() % 2] << std::endl;

	std::cout << "\033[1;34mMaking sure it throws exception when accessing a range out of bonds: \033[0m" << std::endl;
    try
    {
        intArr[40];
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[0;31m" << e.what() << "\033[0m" << '\n';
    }
}
