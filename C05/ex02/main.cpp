#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat b1(1, "B1");
		Bureaucrat b2(150, "B2");
		RobotomyRequestForm f1("F1");
		PresidentialPardonForm f2("F2");
		ShrubberyCreationForm f3("F3");
		std::cout << b1;
		std::cout << b2;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
		b1.signForm(f1);
		b2.signForm(f2);
		b1.executeForm(f1);
		b1.executeForm(f2);
		b1.executeForm(f3);
		b2.signForm(f3);
		b1.signForm(f3);
		b1.executeForm(f3);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}