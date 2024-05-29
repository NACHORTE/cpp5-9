#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
	// Constructors and destructor
		PresidentialPardonForm(std::string target = "Default");
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm();

	// Setters and getters
		
	// Member functions
	void execute(Bureaucrat const & executor) const;

	// Operator overloads
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

	
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
