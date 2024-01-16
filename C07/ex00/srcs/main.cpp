#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 20, b = 34;
	std::string str1 = "Hello World", str2 = "Hello everyone";

	std::cout << "\033[1;34mTesting with integers >> a = 20 and b = 34 \033[0m" << std::endl;
	std::cout << "\033[1;34mMin: \033[0m"<< min(a,b) << std::endl;
	std::cout << "\033[1;34mMax: \033[0m" << max(a,b) << std::endl;

	std::cout << "\033[1;34mSwap: \033[0m";
	swap(a,b);
	std::cout << "a = " << a;
	std::cout << " and b = " << b << std::endl;

	std::cout << std::endl << "\033[1;33mTesting with strings >> str1 = \"Hello World\" and str2 = \"Hello everyone\" \033[0m" << std::endl;
	std::cout << "\033[1;33mSwap: \033[0m";
	swap(str1,str2);
	std::cout << "str1 = " << str1;
	std::cout << " and str2 = " << str2 << std::endl;
	std::cout << "\033[1;34mMin: \033[0m"<< min(str1.c_str(),str2.c_str()) << std::endl;
	std::cout << "\033[1;34mMax: \033[0m" << max(str1.c_str(),str2.c_str()) << std::endl;
	return (0);
}
