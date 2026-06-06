#include "Span.hpp"
#include <cmath>
#include <limits>
#include <algorithm>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) : _n(other._n), _vec(other._vec) {}

Span& Span::operator=(const Span& other) {
    if (this != &other)
    {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_vec.size() >= _n)
        throw FullSpanException();
    _vec.push_back(number);
}

int Span::shortestSpan() const
{
    if (_vec.size() <= 1)
        throw NotEnoughNumbersException();
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_vec.size() <= 1)
        throw NotEnoughNumbersException();
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}
