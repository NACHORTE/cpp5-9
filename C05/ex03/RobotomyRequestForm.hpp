#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
	// Constructors and destructor
		RobotomyRequestForm(std::string target = "Default");
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm();

	// Setters and getters
		
	// Member functions
	void execute(Bureaucrat const & executor) const;

	// Operator overloads
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

	
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
