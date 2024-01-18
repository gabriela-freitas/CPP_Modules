#include "Span.hpp"
#include <list>
#define MAX 10000
#include "testingUtils.hpp"

/*
Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
*/

int main(void)
{
    std::srand(std::time(0));

    int capacity = (std::rand() % 20) + 2;
    Span test(capacity);

    printRed(" >> Testing getting spans before adding numbers, should throw exception");
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

    printBlue(" >> Testing adding numbers to the span using a list");

    std::cout << "Span size: " << test.span().size() << " and capacity: " << test.capacity() << std::endl;
    std::cout << test << std::endl;
    std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
    std::cout << "Longest span: " << test.longestSpan() << std::endl;

    printRed(" >> And now, let's add one more number and wait for an exception");
    try
    {
        test.addNumber(12);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    printBlue(" >> Lastly, let's create a really big span");
    std::vector<int> seed;
    Span bigSpan(MAX);

    seedContainerRandomNumbers(seed, MAX);
    bigSpan.insertRange(seed.begin(), seed.end());
    std::cout << "big span size: " << bigSpan.span().size() << std::endl;
    std::cout << "shortest span: " << test.shortestSpan() << std::endl;
    std::cout << "longest span: " << test.longestSpan() << std::endl;

    return (0);
}
