#pragma once

#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int number);
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) > static_cast<long>(_n - _vec.size()))
                throw FullSpanException();
            _vec.insert(_vec.end(), begin, end);
        }
        int shortestSpan() const;
        int longestSpan() const;
        class FullSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Span is already full"; }
        };
        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Not enough numbers to find a span"; }
        };
};
