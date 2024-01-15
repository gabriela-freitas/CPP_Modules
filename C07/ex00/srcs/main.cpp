#include "whatever.hpp"
#include <iostream>

//TODO: include more tests :)
int	main(void)
{
	int a = 20, b = 34;
	std::string str1 = "Hello World", str2 = "Hello everyone";

	std::cout << min(a,b) << std::endl;
	std::cout << max(a,b) << std::endl;

	swap(a,b);
	std::cout << "a (20) = " << a << std::endl;
	std::cout << "b (34) = " << b << std::endl;

	return (0);
}
