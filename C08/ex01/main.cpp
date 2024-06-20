#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	{
		std::cout << "SUBJECT TEST" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortestSpan:"<<std::endl;
		std::cout << "\tExpected "<< 2 << std::endl;
		std::cout << "\tfunction " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:"<<std::endl;
		std::cout << "\tExpected "<< 14 << std::endl;
		std::cout << "\tfunction " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "ERROR CHECKING" << std::endl;
		std::cout << "1-addNumber to full list" << std::endl;
		std::cout << "Creating span of " << "N = 1" << std::endl;
		Span sp(1);
		std::cout << "Trying to add a number" << std::endl;
		sp.addNumber(100);
		try
		{
			std::cout << "Trying to add another one" << std::endl;
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "2-Shortest and longest span in too short list" << std::endl;
		try
		{
			std::cout << "Trying to execute shortestSpan on previous span of " << "N = 1" << std::endl;
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Trying to execute longestSpan on previous span of " << "N = 1" << std::endl;
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "3-Adding a range of numbers too big" << std::endl;
		std::cout << "Creating a list of " << "100" << " elements" << std::endl;
		std::list<int> list(100,3);
		try
		{
			std::cout << "Trying to add the list to the span of " << "N = 1" << std::endl;
			sp.addRange(list.begin(),list.end());
		}
		catch(const std::exception& e)
		{
			std::cout << "Got exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "WORKING CASES" << std::endl;
		{
			std::cout << "1-Span with only 2 numbers" << std::endl;
			std::cout << "Creating span containing " << "(1,3)" << std::endl;
			Span sp(2);
			sp.addNumber(1);
			sp.addNumber(3);
			std::cout << "shortestSpan is " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "2-Span with same numbers" << std::endl;
			std::cout << "Creating span containing " << "(4,4,4)" << std::endl;
			Span sp(3);
			sp.addNumber(4);
			sp.addNumber(4);
			sp.addNumber(4);
			std::cout << "shortestSpan is " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "3-Adding range of numbers" << std::endl;
			std::cout << "Creating a list containing " << "(10,3,5,7,2)" << std::endl;
			std::list<int> list;
			list.push_back(10);
			list.push_back(3);
			list.push_back(5);
			list.push_back(7);
			list.push_back(2);
			std::cout << "Creating a Span of " << "N = 10" << std::endl;
			Span sp(10);
			std::cout << "Adding the list to Span with addRange" << std::endl;
			sp.addRange(list.begin(),list.end());
			std::cout << "shortestSpan is " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp.longestSpan() << std::endl;
			std::cout << "Creating a list containing " << "(-10,-3,-5,-7,-2)" << std::endl;
			std::list<int> list2;
			list2.push_back(-10);
			list2.push_back(-3);
			list2.push_back(-5);
			list2.push_back(-7);
			list2.push_back(-2);
			std::cout << "Adding the list to Span with addRange" << std::endl;
			sp.addRange(list2.begin(),list2.end());
			std::cout << "shortestSpan is " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "4-10k Numbers" << std::endl;
			std::cout << "Creating a span with " << "10k Numbers (0,...,10000)" << std::endl;
			size_t num = 10000;
			Span sp(num);
			for (size_t i = 0; i < num; i ++)
				sp.addNumber(i);
			std::cout << "shortestSpan is " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp.longestSpan() << std::endl;
			std::cout << "Creating a span with "<< "10k random numbers" << std::endl;
			Span sp2(num);
			std::srand(std::time(0));
			for (size_t i = 0; i < num; i ++)
				sp2.addNumber(rand());
			std::cout << "shortestSpan is " << sp2.shortestSpan() << std::endl;
			std::cout << "longestSpan is " << sp2.longestSpan() << std::endl;
		}
	}
}