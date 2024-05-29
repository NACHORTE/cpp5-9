#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat(150, "Bureaucrat");
	std::cout << *bureaucrat;
	try
	{
		bureaucrat->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete bureaucrat;
	Bureaucrat *bureaucrat2 = new Bureaucrat(1, "Bureaucrat2");
	std::cout << *bureaucrat2;
	try
	{
		bureaucrat2->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete bureaucrat2;
	Bureaucrat *bureaucrat3 = new Bureaucrat(150, "Bureaucrat3");
	std::cout << *bureaucrat3;
	try
	{
		bureaucrat3->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *bureaucrat3;
	delete bureaucrat3;
	Bureaucrat *bureaucrat4 = new Bureaucrat(1, "Bureaucrat4");
	std::cout << *bureaucrat4;
	try
	{
		bureaucrat4->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *bureaucrat4;
	delete bureaucrat4;
	return (0);
}