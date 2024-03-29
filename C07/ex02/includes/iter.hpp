#pragma once

#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
struct FunctionPointer {
   typedef T (type)(T);
};

template <typename array>
void print(array *arr, unsigned int len)
{
    for (unsigned int it = 0; it < len; it++)
    {
        std::cout << *(arr + it) << " ";
    }
    std::cout << std::endl;
}

template <typename array>
void iter(array *arr, unsigned int len, typename FunctionPointer<array>::type func)
{
    std::cout << "Before: ";
    print(arr, len);
    for (unsigned int it = 0; it < len; it++)
    {
        *(arr + it) = func(1);
    }
    std::cout << "After: ";
    print(arr, len);
}

template <typename T>
T multiplyBy2(T num)
{
	return (2 * num);
}

template <typename T>
T decrement(T num)
{
	return (--num);
}

template <typename T>
T random(T num)
{
	std::srand(std::time(0));
    int RandNumber = (std::rand() % num);

	return (RandNumber + ' ');
}
