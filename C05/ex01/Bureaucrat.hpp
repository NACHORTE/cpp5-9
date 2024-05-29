#pragma once
#include <iostream>
#include <string>
#include <exception>
class Form;
class Bureaucrat
{
	public:
	// Constructors and destructor
		Bureaucrat(int grade = 150, std::string name = "Default");
		Bureaucrat(const Bureaucrat & src);
		~Bureaucrat();

	// Setters and getters
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);		
	// Member functions
	void signForm(Form & form);
	// Operator overloads
		Bureaucrat & operator=(const Bureaucrat & rhs);

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
	protected:
	private:
	// Atributes
	const std::string _name;
	int _grade;
	// Private member functions

	
};

std::ostream & operator<<(std::ostream & o, const Bureaucrat & rhs);