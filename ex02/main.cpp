#include <iostream>
#include "MutantStack.hpp"

static void forwardIteration()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Forward iteration:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> regularCopy(mstack);
    std::cout << "Copied to std::stack, size: " << regularCopy.size() << std::endl;
}

static void reverseIteration()
{
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i)
        mstack.push(i * 2);

    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;
}

int main()
{
    forwardIteration();
    reverseIteration();
    std::stack<int> copy; // ensures compatibility with std::stack constructors
    copy = std::stack<int>(MutantStack<int>());
    (void)copy;
    return 0;
}
