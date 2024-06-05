#pragma once
#include <iostream>

class ScalarConverter
{
	public:
	// Constructors and destructor
		~ScalarConverter();

	// Setters and getters
		
	// Member functions
	static void convert(const std::string &str);


	protected:
	private:
	// Atributes

	// Private member functions
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter & src);
	ScalarConverter & operator=(const ScalarConverter & rhs);

};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &obj);
