#pragma once
#include <iostream>
#include <map>

class BitcoinExchange
{
	public:
	// Constructors and destructor
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange & src);
		~BitcoinExchange();

	// Setters and getters
		
	// Member functions
	int readData(const std::string &filename);
	int readInput(const std::string &input);

	// Operator overloads
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

	protected:
	private:
	// Atributes
	std::map <std::string, float> _data;

	// Private member functions

};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &obj);
