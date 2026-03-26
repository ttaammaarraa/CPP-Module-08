#include "Span.hpp"

Span::Span() : _maxSize(0), _data()
{
}

Span::Span(unsigned int n) : _maxSize(n), _data()
{
    _data.reserve(n);
}

Span::Span(Span const &other) : _maxSize(other._maxSize), _data(other._data)
{
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _data.push_back(value);
}

unsigned int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");

    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = static_cast<unsigned int>(-1);
    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");

    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}

unsigned int Span::size() const
{
    return static_cast<unsigned int>(_data.size());
}

unsigned int Span::capacity() const
{
    return _maxSize;
}
