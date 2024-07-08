#pragma once
#include <iostream>
#include <stack>

class RPN
{
	public:
	// Constructors and destructor
		RPN(void);
		RPN(const RPN & src);
		~RPN();

		static int calculate(const std::string & str);


		RPN & operator=(const RPN & rhs);

	protected:
	private:

};