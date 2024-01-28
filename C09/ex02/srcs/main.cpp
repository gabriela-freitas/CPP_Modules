#include <deque>
#include <iostream>
#include <algorithm>
#include <testingUtils.hpp>

typedef std::deque<int> Cont;
typedef std::deque<int>::iterator Iterator;

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

void print(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void insertionSort(Iterator begin, Iterator end)
{
	int key;
	Iterator j;
	for (Iterator i = begin + 1; i < end; i++)
	{
		key = *(i + 1);
		for (j = i + 1; j > begin && *(j - 1) > key; j--)
			*j = *(j - 1);
		*j = key;
	}
}

// void insertionSort(Iterator begin, Iterator end)
// {
// 	for (Iterator it = begin; it < end; it++)
// 	{
// 		if (it + 1 == end)
// 			break;
// 		int tempVal = *(it + 1);
// 		Iterator j = it + 1;
// 		while (j > begin && *(j - 1) > tempVal)
// 		{
// 			*j = *(j - 1);
// 			j--;
// 		}
// 		*j = tempVal;
// 	}
// }

// The purpose of this merge function is to merge two sorted subarrays within the larger array A
// into a single sorted subarray.
// This function is commonly used in sorting algorithms like Merge Sort.

void merge(Cont &original, Iterator begin, Iterator half, Iterator end)
{
	Iterator it;
	Iterator pos;
	int i = 0;

	Cont v(begin, half);
	Cont temp(half, end);

	for (it = temp.begin(); it != temp.end(); it++, i++)
	{
		pos = std::lower_bound(v.begin(), v.end(), *it);
		if (pos == begin)
			v.push_front(*it);
		else if (pos == v.end())
			v.push_back(*it);
		else
			v.insert(pos, *it);
	}
	for (it = begin, pos ; it != end; it++)
	{
		*it = 
	}
}

void sort(Cont &v, Iterator begin, Iterator end)
{
	std::size_t distance = std::distance(begin, end);
	if (distance > 2)
	{
		Iterator half = begin + (distance / 2);
		printBlue(">>>");
		print(begin, half);
		print(half, end);
		sort(v, begin, half); // does sort of first half
		sort(v, half, end);	  // does sort on second half
		merge(v, begin, half, end);
	}
	else
	{
		if (*begin > *end)
		{
			int temp = *begin;
			*begin = *end;
			*end = temp;
		}
		// insertionSort(begin, end);
	}
}

int main()
{
	Cont a;

	// seedContainerRandomNumbers(a, 20);
	a.push_back(9);
	a.push_back(8);
	a.push_back(7);
	a.push_back(6);
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	print(a);
	sort(a, a.begin(), a.end());
	print(a);
	if (!is_sorted(a))
		printRed("WRONG!");
}

// int main(void)
// {
// 	PmergeMe p;
// 	std::cont<int> a;
// 	a.push_back(34);
// 	a.push_back(6);
// 	a.push_back(5);
// 	a.push_back(3);
// 	a.push_back(4);
// 	a.push_back(2);
// 	a.push_back(1);
// 	a.push_back(12);
// 	p.sort(a);
// 	std::cont<int> b = a;
// 	std::cont<int>::iterator it;

// 	for (it = b.begin(); it != b.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }
