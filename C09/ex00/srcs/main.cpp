#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
	BitcoinExchange bitcoinExchange;
	try
	{
		if (ac == 2)
			bitcoinExchange.calculateExchangeRate(av[1]);
		else
			printRed("Provide a input file");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
