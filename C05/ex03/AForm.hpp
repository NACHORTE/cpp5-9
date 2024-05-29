#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
	public:
	// Constructors and destructor
		AForm(std::string name = "Default", int signGrade = 150, int execGrade = 150);
		AForm(const AForm & src);
		virtual ~AForm();

	// Setters and getters
		
	// Member functions
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getIsSigned(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;


	// Operator overloads
		AForm & operator=(const AForm & rhs);

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

std::ostream &operator<<(std::ostream &os, const AForm &obj);
