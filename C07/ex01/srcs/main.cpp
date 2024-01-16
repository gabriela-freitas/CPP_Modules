#include "iter.hpp"


//Turn in a main.cpp file that contains your tests. Provide enough code to generate a
// test executable.

char toUpperChar(char c)
{
	return ((char)toupper(c));
}

int	main(void)
{
	int a[4] = {1, 2, 3, 4};
	char str[] = "Hello World";

	std::cout << "\033[1;34mTesting in a int array: \033[0m" << std::endl;

	std::cout << "\033[0;34mMultiply by 2\033[0m" << std::endl;
	iter(a, 4, &multiplyBy2<int>);
	std::cout << "\033[0;34mApplying Decrement\033[0m" << std::endl;
	iter(a, 4, &decrement<int>);
	std::cout << "\033[0;34mApplying Random\033[0m" << std::endl;
	iter(a, 4, &random<int>);

	std::cout << std::endl << "\033[1;34mTesting in a char array: \033[0m" << std::endl;

	std::cout << "\033[0;34mtoUpper\033[0m" << std::endl;
	iter(str, strlen(str), &toUpperChar);
	std::cout << "\033[0;34mRandom\033[0m" << std::endl;
	iter(str, strlen(str), &random<char>);
	std::cout << "\033[0;34mDecrement\033[0m" << std::endl;
	iter(str, strlen(str), &decrement<char>);

	return (0);
}
