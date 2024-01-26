
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
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
	void sort(std::vector<int> &vector);
	void sort(std::list<int> &list);

private:
	void sortPairs(std::pair<int, int> &pair);
	std::vector<int> &insert(std::vector<int> &a, std::vector<int> &b);
	std::list<int> &insert(std::list<int> &a, std::list<int> &b);
	template <typename T>
	bool is_sorted(T cont)
	{
		typename T::iterator it;

		for (it = cont.begin(); it != cont.end() - 1; it++)
		{
			if (*it > *(it + 1))
				return false;
		}
		return true;
	}
};
std::ostream &operator<<(std::ostream &, const PmergeMe &);
#endif
