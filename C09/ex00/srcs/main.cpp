#include "BitcoinExchange.hpp"



int main(void)
{
	BitcoinExchange bitcoinExchange;
	try
	{
		bitcoinExchange.registerInfomations("input.txt");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
