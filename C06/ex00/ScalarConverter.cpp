#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>

ScalarConverter::~ScalarConverter()
{
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &obj)
{
	(void)obj;
	return (os);
}

bool isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	return false;
}

bool isInt(const std::string &str)
{
	long long int num;
	num = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (!isdigit(str[i]))
			return false;
		num = num * 10 + str[i] - '0';
		if (num > std::numeric_limits<int>::max())
			return false;
	}
	return true;
}

bool isFloat(const std::string &str)
{
	bool started = false;
	int dot = 0;
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			dot++;
			if (dot > 1 || !started)
				return false;
			continue;
		}
		if (!isdigit(str[i]))
			return false;
		started = true;
	}
	if (dot == 0 || str[str.length() - 1] != 'f' || str.length() < 4 || str[str.length() - 2] == '.')
		return false;
	return true;
}

bool isDouble(const std::string &str)
{
	bool started = false;
	int dot = 0;
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] == '.')
		{
			dot++;
			if (dot > 1 || !started)
				return false;
			continue;
		}
		if (!isdigit(str[i]))
			return false;
		started = true;
	}
	if (dot == 0 || str[str.length() - 1] == '.')
		return false;
	return true;
}

int getType(const std::string &str)
{
	if (isChar(str))
		return 1;
	else if (isInt(str))
		return 2;
	else if (isFloat(str))
		return 3;
	else if (isDouble(str))
		return 4;
	return 5;
}

void convertChar(const std::string &str)
{
	char c = str[0];
	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void convertInt(const std::string &str)
{
	int a = atoi(str.c_str());
	if (isascii(a) && std::isprint(a))
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else if (isascii(a))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << ".0" << std::endl;
}

void convertFloat(const std::string &str)
{
	float a = atof(str.c_str());
	bool overflow = false;
	if (a > std::numeric_limits<int>::max() || a < std::numeric_limits<int>::min())
		overflow = true;
	int b = static_cast<int>(a);
	if(overflow || std::isnan(a) || std::isinf(a) || !isascii(b))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(b))
		std::cout << "char: '" << static_cast<char>(a) << "'" <<std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (overflow || std::isnan(a) || std::isinf(a))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << b << std::endl;
	std::cout << "float: " << a << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void convertDouble(const std::string &str)
{
	double a = atof(str.c_str());
	bool overflow = false;
	if (a > std::numeric_limits<int>::max() || a < std::numeric_limits<int>::min())
		overflow = true;
	int b = static_cast<int>(a);
	if(overflow || std::isnan(a) || std::isinf(a) || !isascii(b))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(b))
		std::cout << "char: '" << static_cast<char>(a) << "'" <<std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (overflow || std::isnan(a) || std::isinf(a))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << b << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << a << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	int type = getType(str);

	switch (type)
	{
	case 1:
		convertChar(str);
		break;
	case 2:
		convertInt(str);
		break;
	case 3:
		convertFloat(str);
		break;
	case 4:
		convertDouble(str);
		break;
	default:
		std::cout << "Error: Invalid input\n";
		break;
	}
}