#include "Span.hpp"

const char *Span::SpanException::what() const throw()
{
    return ("Span capacity is reached, cannot add anymore numbers");
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &param) : _N(param.capacity()),
                                _span(param.span()), _shortestSpan(0)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &param)
{

    if (param.capacity() > _N)
        throw SpanException();

    _span = param.span();
    return (*this);
}

const std::vector<int> &Span::span() const
{
    return _span;
}

size_t Span::capacity() const
{
    return _N;
}

int Span::longestSpan() const
{
    if (_span.size() < 2)
        throw std::exception();
    return abs(*_span.rbegin() - *_span.begin());
}

int Span::shortestSpan() const
{
    if (_span.size() < 2)
        throw std::exception();
    return (_shortestSpan);
}

void Span::addNumber(int newNumber)
{
    if (_span.size() + 1 > _N)
        throw SpanException();
    std::vector<int>::iterator it = std::upper_bound(_span.begin(), _span.end(), newNumber);
    it = _span.insert(it, newNumber);

    if (_span.size() == 2)
    {
        _shortestSpan = abs(_span[1] - _span[0]);
    }
    if (it + 1 < _span.end() && abs(*(it + 1) - *it) < _shortestSpan)
    {
        _shortestSpan = abs(*(it + 1) - *it);
    }
    if (it - 1 > _span.begin() && abs(*(it - 1) - *it) < _shortestSpan)
    {
        _shortestSpan = abs(*it - *(it - 1));
    }
}

std::ostream &operator<<(std::ostream &os, const Span &param)
{
    os << "Span: ";
    for (std::vector<int>::const_iterator it = param.span().begin(); it != param.span().end(); it++)
    {
        os << *it << " ";
    }
    return os;
}
