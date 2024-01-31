
#include "PmergeMe.hpp"
#include "InvalidInputExeception.hpp"

static void mergeInsertionSort(std::list<int> &A);
static void mergeInsertionSort(std::vector<int> &A, int p, int r);

std::string PmergeMe::sort(std::vector<int> &vector)
{
	std::clock_t start, end;
	start = clock();
	mergeInsertionSort(vector, 0, vector.size() - 1);
	// Recording the end clock tick.
	end = clock();
	// Calculating total time taken by the program.
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::stringstream ss;
	ss << "Time to process a range of " << vector.size()
	   << " elements with std::vector: " << std::fixed
	   << time_taken;
	ss << " sec ";
	if (!is_sorted(vector))
		throw InvalidInputExeception("Failed to sort with std::vector");
	return ss.str();
}

std::string PmergeMe::sort(std::list<int> &list)
{
	std::clock_t start, end;
	start = clock();
	mergeInsertionSort(list);
	// Recording the end clock tick.
	end = clock();
	// Calculating total time taken by the program.
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::stringstream ss;
	ss << "Time to process a range of " << list.size()
	   << " elements with std::list: " << std::fixed
	   << time_taken;
	ss << " sec ";
	if (!is_sorted(list))
		throw InvalidInputExeception("Failed to sort with std::list");
	return ss.str();
}

PmergeMe::PmergeMe()
{
	std::srand(std::time(0));
	printBlue("Generating random sequence:");
	seedContainerRandomNumbers(vector, 42);
	seedSecondContainer(vector, list);
	printGreen("Before: ", vector);
	std::string res = sort(vector);
	printYellow("After: ", vector);
	std::cout << res << std::endl;
	std::cout << sort(list);
	std::cout << std::endl;
	std::cout << std::endl;
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

		if (check.str().compare(ss.str()) || number < 0)
			throw InvalidInputExeception("Error");

		vector.push_back(number);
		list.push_back(number);
		numbers++;
	}
	printGreen("Before: ", vector);
	std::string res = sort(vector);
	printYellow("After: ", vector);
	std::cout << res << std::endl;
	std::cout << sort(list);
	std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &param)
{
	(void)param;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &param)
{
	(void)param;
	return (*this);
}

static void merge(std::vector<int> &A, int p, int q, int r)
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

static void insertionSort(std::vector<int> &A, int p, int q)
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

static void mergeInsertionSort(std::vector<int> &A, int p, int r)
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



static std::list<int>::iterator next(std::list<int>::iterator it)
{
	std::list<int>::iterator newIt = it;
	std::advance(newIt, 1);
	return newIt;
}

static std::list<int>::iterator prev(std::list<int>::iterator it)
{
	std::list<int>::iterator newIt = it;
	std::advance(newIt, -1);
	return newIt;
}

static void insertionSort(std::list<int> &myList)
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

static void mergeInsertionSort(std::list<int> &A)
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
