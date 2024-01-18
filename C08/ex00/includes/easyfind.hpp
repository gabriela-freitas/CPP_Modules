#pragma once

#include <algorithm>

// A first easy exercise is the way to start off on the right foot.
// Write a function template easyfind that accepts a type T. It takes two parameters.
//  - The first one has type T and the second one is an integer.
//      Assuming T is a container of integers, this function has to find the first occurrence
//          of the second parameter in the first parameter.
//      If no occurrence is found, you can either throw an exception or return an error value
//          of your choice. If you need some inspiration, analyze how standard containers behave.

// You don’t have to handle associative containers.

// Of course, implement and turn in your own tests to ensure everything works as ex-
// pected.

template <typename T>
typename T::iterator easyfind(T container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);

    if (it == container.end())
        throw(std::exception());
    else
        return it;
}
