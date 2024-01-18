#include "Span.hpp"
#include <list>
#include <cstdlib>
#include <ctime>
#define MAX 10000

/*
Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
*/
template <typename Container>
void seedContainerRandomNumbers(Container &container, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        int RandNumber = (std::rand() % (n * 10));
        container.push_back(RandNumber);
    }
}

// TODO: prettify tests
int main(void)
{
    std::srand(std::time(0));
    int capacity = (std::rand() % 20) + 2;
    Span test(capacity);

    std::cout << "Testing getting spans before adding numbers, should throw exception" << std::endl;
    try
    {
        test.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::list<int> list;
    seedContainerRandomNumbers(list, capacity);
    test.insertRange(list.begin(), list.end());

    std::cout << "big span size: " << test.span().size() << " and capacity: " << test.capacity() << std::endl;
    std::cout << test << std::endl;
    std::cout << "shortest span: " << test.shortestSpan() << std::endl;
    std::cout << "longest span: " << test.longestSpan() << std::endl;

    std::cout << "Testing inserting one more to see it throws exception" << std::endl;
    try
    {
        test.addNumber(12);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<int> seed;
    Span bigSpan(MAX);

    seedContainerRandomNumbers(seed, MAX);
    bigSpan.insertRange(seed.begin(), seed.end());
    std::cout << "big span size: " << bigSpan.span().size() << std::endl;
    std::cout << "shortest span: " << test.shortestSpan() << std::endl;
    std::cout << "longest span: " << test.longestSpan() << std::endl;

    return (0);
}
