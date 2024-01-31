#include "testingUtils.hpp"
#include "PmergeMe.hpp"
int main(int ac, char **av)
{
	try
	{
		PmergeMe p;
		if (ac > 2)

			PmergeMe a(++av);
	}
	catch (const std::exception &e)
	{
		printRed(e.what());
	}
	return 0;
}
