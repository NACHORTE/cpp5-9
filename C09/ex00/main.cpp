#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ex00 <filename>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	(void)argv;
	if (exchange.readData("data.csv"))
	{
		return (1);
	}
	if (exchange.readInput(argv[1]))
	{
		return (1);
	}
	return (0);
}