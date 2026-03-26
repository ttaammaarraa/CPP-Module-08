#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
    Span();
    explicit Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addRange(InputIt first, InputIt last)
    {
        for (InputIt it = first; it != last; ++it)
        {
            if (_data.size() >= _maxSize)
                throw std::runtime_error("Span is full");
            _data.push_back(*it);
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;

private:
    unsigned int _maxSize;
    std::vector<int> _data;
};

#endif
