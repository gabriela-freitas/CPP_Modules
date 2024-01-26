#include "PmergeMe.hpp"

template <typename T>
void print(T &cont)
{
	typename T::iterator it;

	for (it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main(void)
{
	PmergeMe p;
	std::vector<int> a;
	a.push_back(34);
	a.push_back(6);
	a.push_back(5);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(1);
	a.push_back(12);
	p.sort(a);
	std::vector<int> b = a;
	std::vector<int>::iterator it;

	for (it = b.begin(); it != b.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}
