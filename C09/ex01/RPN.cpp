#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cctype>

RPN::RPN(void)
{}

RPN::RPN(const RPN & src)
{
	*this = src;
}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	return (*this);
}

static bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void add(std::stack<double> & stack)
{
	double n2 = stack.top();
	stack.pop();
	double n1 = stack.top();
	stack.pop();
	stack.push(n1 + n2);
}

void substract(std::stack<double> & stack)
{
	double n2 = stack.top();
	stack.pop();
	double n1 = stack.top();
	stack.pop();
	stack.push(n1 - n2);
}

void multiply(std::stack<double> & stack)
{
	double n2 = stack.top();
	stack.pop();
	double n1 = stack.top();
	stack.pop();
	stack.push(n1 * n2);
}

void divide(std::stack<double> & stack)
{
	double n2 = stack.top();
	stack.pop();
	double n1 = stack.top();
	stack.pop();
	if (n2 == 0)
		throw std::runtime_error("Error");
	stack.push(n1 / n2);
}

int RPN::calculate(const std::string & str)
{
	std::istringstream iss(str);
	std::stack<double> stack;

	while(!iss.eof())
	{
		std::string line;
		std::getline(iss,line,' ');
		if (line.empty())
			continue;
		if(line.size() != 1
			|| (!isdigit(line[0]) && !isOperator(line[0]))
			|| (isOperator(line[0]) && stack.size() < 2))
			throw std::runtime_error("Error");

		if (isdigit(line[0]))
			stack.push(line[0] - '0');
		else if (line[0] == '+')
			add(stack);
		else if (line[0] == '-')
			substract(stack);
		else if (line[0] == '*')
			multiply(stack);
		else if (line[0] == '/')
			divide(stack);
	}

	if (stack.size() > 1)
		throw std::runtime_error("Error");

	if (stack.size() == 0)
		return 0;

	return stack.top();
}