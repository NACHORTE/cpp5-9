#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
	// Constructors and destructor
		Intern(void);
		Intern(const Intern & src);
		~Intern();

	// Setters and getters
		
	// Member functions
	AForm * makeForm(std::string formName, std::string target);

	// Operator overloads
		Intern & operator=(const Intern & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

};

std::ostream &operator<<(std::ostream &os, const Intern &obj);
