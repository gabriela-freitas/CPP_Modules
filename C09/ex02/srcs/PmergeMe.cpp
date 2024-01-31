
#include "PmergeMe.hpp"
#include "InvalidInputExeception.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **numbers)
{

	while (numbers && *numbers)
	{
		std::stringstream ss;
		int number;
		std::stringstream check;
		ss << *numbers;
		ss >> number;
		check << number;

		if (check.str().compare(ss.str()))
			throw InvalidInputExeception("Invalid");

		vector.push_back(number);
		list.push_back(number);
		numbers++;
	}
	sort(vector);
	sort(list);
}

PmergeMe::PmergeMe(const PmergeMe &param)
{
	// TODO (copy constructor)
	(void)param;
}
PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe"
			  << " destroyed" << std::endl;
	// TODO (destructor)
}
PmergeMe &PmergeMe::operator=(const PmergeMe &param)
{
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}
std::ostream &operator<<(std::ostream &s, const PmergeMe &param)
{
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

void merge(std::vector<int> &A, int p, int q, int r)
{
	std::vector<int> firstHalf(A.begin() + p, A.begin() + q + 1);
	std::vector<int> secondHalf(A.begin() + q + 1, A.begin() + r + 1);

	std::vector<int>::iterator fisrtIt = firstHalf.begin();
	std::vector<int>::iterator SecondIt = secondHalf.begin();

	for (int i = p; i <= r; i++)
	{
		if (SecondIt == secondHalf.end())
		{
			A[i] = *fisrtIt;
			fisrtIt++;
		}
		else if (fisrtIt == firstHalf.end())
		{
			A[i] = *SecondIt;
			SecondIt++;
		}
		else if (*SecondIt > *fisrtIt)
		{
			A[i] = *fisrtIt;
			fisrtIt++;
		}
		else
		{
			A[i] = *SecondIt;
			SecondIt++;
		}
	}
}

void insertionSort(std::vector<int> &A, int p, int q)
{
	for (int i = p; i < q; i++)
	{
		int tempVal = A[i + 1];
		int j = i + 1;
		while (j > p && A[j - 1] > tempVal)
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tempVal;
	}
}

void mergeInsertionSort(std::vector<int> &A, int p, int r)
{
	if (r - p > 5)
	{
		int q = (p + r) / 2;
		mergeInsertionSort(A, p, q);
		mergeInsertionSort(A, q + 1, r);
		merge(A, p, q, r);
	}
	else
	{
		insertionSort(A, p, r);
	}
}

void PmergeMe::sort(std::vector<int> &vector)
{
	mergeInsertionSort(vector, 0, vector.size() - 1);
	if (is_sorted(vector))
		printGreen("SORTED!");
	else
		printRed("NOT SORTED :(((");
}

std::list<int>::iterator next(std::list<int>::iterator it)
{
	std::list<int>::iterator newIt = it;
	std::advance(newIt, 1);
	return newIt;
}

std::list<int>::iterator prev(std::list<int>::iterator it)
{
	std::list<int>::iterator newIt = it;
	std::advance(newIt, -1);
	return newIt;
}

void insertionSort(std::list<int> &myList)
{
	for (std::list<int>::iterator it = next(myList.begin()); it != myList.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator insertPos = it;

		while (insertPos != myList.begin() && *prev(insertPos) > key)
		{
			std::iter_swap(insertPos, prev(insertPos));
			--insertPos;
		}

		*insertPos = key;
	}
}

void mergeInsertionSort(std::list<int> &A)
{
	if (A.size() > 5)
	{
		std::list<int> secondList;
		std::list<int>::iterator it;
		it = A.begin();
		std::advance(it, A.size() / 2);
		secondList.splice(secondList.begin(), A, A.begin(), it);
		mergeInsertionSort(A);
		mergeInsertionSort(secondList);
		A.merge(secondList);
	}
	else
	{
		insertionSort(A);
	}
}

void PmergeMe::sort(std::list<int> &list)
{
	mergeInsertionSort(list);
	if (is_sorted(list))
		printGreen("SORTED!");
	else
		printRed("NOT SORTED :(((");
}