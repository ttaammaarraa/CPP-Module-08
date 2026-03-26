#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void basicTest()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

static void bulkTest()
{
    const unsigned int count = 10000;
    Span sp(count);

    std::vector<int> values;
    values.reserve(count);
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (unsigned int i = 0; i < count; ++i)
        values.push_back(std::rand());

    sp.addRange(values.begin(), values.end());

    std::cout << "Bulk size: " << sp.size() << " / " << sp.capacity() << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

static void overflowTest()
{
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try
    {
        sp.addNumber(3);
    }
    catch (std::exception const &e)
    {
        std::cout << "Overflow test caught: " << e.what() << std::endl;
    }
}

int main()
{
    try
    {
        basicTest();
        bulkTest();
        overflowTest();
    }
    catch (std::exception const &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
