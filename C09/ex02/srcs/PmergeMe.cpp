
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// TODO (default constructor)
}
PmergeMe::PmergeMe(const PmergeMe& param) {
	// TODO (copy constructor)
	(void)param;
}
PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe" << " destroyed" << std::endl;
	// TODO (destructor)
}
PmergeMe& PmergeMe::operator= (const PmergeMe& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream& operator<<(std::ostream& s, const PmergeMe& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

void PmergeMe::sortPairs(std::pair<int, int> &pair)
{
	if (pair.second < pair.first)
		std::swap(pair.second, pair.first);
}

std::vector<int> & PmergeMe::insert(std::vector<int> &a, std::vector<int> &b)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator pos;

	for (it = b.begin(); it != b.end(); it++)
	{
		pos = std::lower_bound(a.begin(), a.end(), *it);
		a.insert(pos, *it);
	}
	return a;
}

void PmergeMe::sort(std::vector<int> &v)
{
	std::vector<int>::iterator it;
	std::vector<int> a, b;

	for (it = v.begin(); it != v.end(); it += 2)
	{
		if (it + 1 == v.end())
		{
			b.push_back(*it);
			break;
		}
		std::pair<int, int> pairs = std::make_pair(*it, *(it + 1));
		sortPairs(pairs);
		a.push_back(pairs.first);
		b.push_back(pairs.second);
	}
	if (!is_sorted(a))
	{
		sort(a);
	}
	v = insert(a, b);
	if (!is_sorted(v))
		sort(v);
}

// void PmergeMe::sort(std::list<int> &v)
// {
// 	if (is_sorted(v))
// 		return ;
// 	std::list<int>::iterator it;
// 	std::list<int> a, b;

// 	for (it = v.begin(); it != v.end(); it++)
// 	{
// 		if (it ++ == v.end())
// 		{
// 			b.push_back(*it);
// 			break;
// 		}
// 		std::pair<int, int> pairs = std::make_pair(*it, *(it + 1));
// 		sortPairs(pairs);
// 		a.push_back(pairs.first);
// 		b.push_back(pairs.second);
// 	}
// 	sort(a);
// 	sort(b);
// 	a.merge(b);
// 	if (!is_sorted(v))
// 		sort(v);
// }