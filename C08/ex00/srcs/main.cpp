#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <deque>
#include <list>

// TODO: tests
int main(void)
{
    std::vector<int> vec(9);
    std::deque<int> deq(9);
    std::list<int> lt(90);

    vec[1] = 2;
    vec[3] = 2;
    std::cout << *easyfind(vec, 2) << std::endl;

    deq[1] = 2;
    deq[3] = 2;
    std::cout << *easyfind(deq, 2) << std::endl;

    *lt.begin() = 2;
    std::list<int>::iterator it = easyfind(lt, 223132132);
    if ( it != lt.end() )
    {
    std::cout << *it << std::endl;
    }
    return (0);
}
