#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	public:
	// Constructors and destructor
		Form(std::string name = "Default", int signGrade = 150, int execGrade = 150);
		Form(const Form & src);
		~Form();

	// Setters and getters
		
	// Member functions
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat &bureaucrat);


	// Operator overloads
		Form & operator=(const Form & rhs);

	// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
	protected:
	private:
	// Atributes
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;
	// Private member functions

};

std::ostream &operator<<(std::ostream &os, const Form &obj);
