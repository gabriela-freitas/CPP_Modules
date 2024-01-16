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

// Implement a function template iter that takes 3 parameters and returns nothing.
// •The first parameter is the address of an array.
// •The second one is the length of the array.
// •The third one is a function that will be call on every element of the array.

// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.

template <typename array>
void iter(array *arr, unsigned int len, typename FunctionPointer<array>::type func)
{
    std::cout << "Before: ";
    print(arr, len);
    for (unsigned int it = 0; it < len; it++)
    {
        *(arr + it) = func(*(arr + it));
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
