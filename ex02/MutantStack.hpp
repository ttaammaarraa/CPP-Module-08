#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
protected:
	using std::stack<T>::c;

public:
	MutantStack();
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();;
	iterator end();
};


template <typename T>
 MutantStack<T>::MutantStack()
{
}

template <typename T>
 MutantStack<T>::~MutantStack()
{
}

template <typename T>
 typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
 typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
