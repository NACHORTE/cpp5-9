#pragma once
#include <iostream>
#include <list>

class Span
{
	public:
	// Constructors and destructor
		Span(int N = 5);
		Span(const Span & src);
		~Span();

	// Setters and getters
		
	// Member functions
		void addNumber(int num);
		void addRange(std::list<int>::iterator first, std::list<int>::iterator last);
		size_t shortestSpan();
		size_t longestSpan();

	// Operator overloads
		Span & operator=(const Span & rhs);
	protected:
	private:
		unsigned int _N;
		std::list<int> _list;
		bool _isSorted;
		size_t _listLen;
};