#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void testVector()
{
    std::vector<int> values;
    values.push_back(10);
    values.push_back(20);
    values.push_back(30);
    values.push_back(40);

    try
    {
        std::vector<int>::iterator it = easyfind(values, 30);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    try
    {
        easyfind(values, 99);
    }
    catch (std::exception const &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }
}

static void testList()
{
    std::list<int> values;
    for (int i = 1; i <= 5; ++i)
        values.push_back(i * 3);
}

int main()
{
    testVector();
    testList();
    return 0;
}
