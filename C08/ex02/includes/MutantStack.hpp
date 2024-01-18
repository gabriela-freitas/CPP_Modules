
#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(const MutantStack &param) : std::stack<T>(param){};
	MutantStack &operator=(const MutantStack &param)
	{
		std::stack<T>::operator=(param);
	};
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	};
	iterator end()
	{
		return (this->c.end());
	}

	//Adding this just to be able to use the same test for the diff containers types
	void push_back(const T& value)
	{
		this->push(value);
	}
};

template <typename T>
std::ostream &operator<<(std::ostream &, const MutantStack<T> &);
