#include "BitcoinExchange.hpp"
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &data)
{
	if (this != &data)
	{
		// copy
	}
	return (*this);
}

bool dateOk(const std::string &date)
{
	tm tm;
	char *ptr;

	ptr = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (ptr == NULL || *ptr != '\0')
	{
		return false;
	}
	return true;
}

std::string trim(const std::string& str, const std::string & charset = " \t\n\r\f\v")
{
    size_t first = str.find_first_not_of(charset);
    if (std::string::npos == first)
        return std::string();
    size_t last = str.find_last_not_of(charset);
    return str.substr(first, (last - first + 1));
}

bool isFloat(const std::string &str)
{
	std::istringstream ss(str);
	float f;
	ss >> f;
	if (ss.fail() || !ss.eof())
	{
		return false;
	}
	return true;
}

float toFloat(const std::string &str)
{
	std::istringstream ss(str);
	float f;
	ss >> f;
	return f;
}

void printMap(const std::map<std::string, float> &m)
{
	for (std::map<std::string, float>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

int BitcoinExchange::readData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}
	std::string line;

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string key;
		float value;

		std::size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad dataset, line => " << line << std::endl;
			file.close();
			return 1;
		}

		key = line.substr(0, pos);

		if (!dateOk(key) || !isFloat(line.substr(pos + 1)))
		{
			std::cerr << "Error: bad dataset, line => " << line << std::endl;
			file.close();
			return 1;
		}
		value = toFloat(line.substr(pos + 1));
		_data[key] = value;
	}
	file.close();
	return 0;
}

int BitcoinExchange::readInput(const std::string &input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << input << std::endl;
		return 1;
	}
	std::string line;

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string key;
		std::string s_value;
		float value;


		if (trim(line).empty())
			continue;
		std::size_t pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		key = trim(line.substr(0, pos));
		s_value = trim(line.substr(pos + 1));

		if (!dateOk(key) || !isFloat(s_value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		value = toFloat(s_value);
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		if (_data.find(key) == _data.end())
		{
			for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
			{
				if (it->first > key)
				{
					if (it == _data.begin())
					{
						std::cout << key << " => " << value << " = " << value * it->second << std::endl;
						break;
					}
					it--;
					std::cout << key << " => " << value << " = " << value * it->second << std::endl;
					break;
				}
			}
			if (_data.rbegin()->first < key)
			{
				std::cout << key << " => " << value << " = " << value * _data.rbegin()->second << std::endl;
			}
		}
		else
		{
			std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
		}
	}
	file.close();
	return 0;
}
