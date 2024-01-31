#include "testingUtils.hpp"
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    // std::srand(std::time(0));
	PmergeMe p;
	// Example usage:
	std::vector<int> arr;
	seedContainerRandomNumbers(arr, 3000);
	p.sort(arr);

	std::list<int> list;
	seedContainerRandomNumbers(list, 3000);
	p.sort(list);
	if (ac > 2)
	{
		try
		{
			PmergeMe a(++av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return 0;
}

