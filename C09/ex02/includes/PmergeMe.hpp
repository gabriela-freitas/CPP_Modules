
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <sstream>
#include "testingUtils.hpp"

class PmergeMe
{
public:
	PmergeMe(char **numbers);
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
	void sort(std::vector<int> &vector);
	void sort(std::list<int> &list);

private:
	template <typename T>
	bool is_sorted(T cont)
	{
		typename T::iterator it;
		typename T::iterator next;

		it = cont.begin();
		next = it; 
		next++;
		for (; next != cont.end(); it++, next++)
		{
			if (*it > *(next))
				return false;
		}
		return true;
	}
	std::vector<int> vector;
	std::list<int> list;
};
std::ostream &operator<<(std::ostream &, const PmergeMe &);
#endif
