#pragma once
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
	// Constructors and destructor
		ShrubberyCreationForm(std::string target = "Default");
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm();

	// Setters and getters
		
	// Member functions
	void execute(Bureaucrat const & executor) const;

	// Exceptions
		class FileError : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

	// Operator overloads
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

	protected:
	private:
	// Atributes

	// Private member functions

};
