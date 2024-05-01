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
	return (0);
}