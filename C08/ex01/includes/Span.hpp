
#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <iostream>
#include <vector>
#include <algorithm>

// Develop a Span class that can store a maximum of N integers. N is an unsigned int
//  variable and will be the only parameter passed to the constructor.
class Span
{
private:
    Span();

public:
    Span(unsigned int N);
    Span(const Span &);
    ~Span();
    Span &operator=(const Span &);
    // This class will have a member function called addNumber() to add a single number
    //  to the Span. It will be used in order to fill it. Any attempt to add a new element if there
    //  are already N elements stored should throw an exception.
    void addNumber(int newNumber);

    // Next, implement two member functions: shortestSpan() and longestSpan()

    // They will respectively find out the shortest span or the longest span (or distance, if
    // you prefer) between all the numbers stored, and return it. If there are no numbers stored,
    // or only one, no span can be found. Thus, throw an exception.
    int shortestSpan() const;

    int longestSpan() const;

    const std::vector<int> &span() const;
    size_t capacity() const;
    class SpanException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    // 	Last but not least, it would be wonderful to fill your Span using a range of iterators.
    // Making thousands calls to addNumber() is so annoying. Implement a member function
    // to add many numbers to your Span in one call.

    // If you don’t have a clue, study the Containers. Some member
    // functions take a range of iterators in order to add a sequence of
    // elements to the container.
    template <typename iterator>
    void insertRange(iterator rangeBegin, iterator rangeEnd)
    {
        for (iterator it = rangeBegin; it != rangeEnd; it++)
        {
            addNumber(*it);
        }
    }

private:
    const size_t _N;
    std::vector<int> _span;
    int _shortestSpan;
};

std::ostream &operator<<(std::ostream &, const Span &);
#endif
