#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1(1, "B1");
		Bureaucrat b2(150, "B2");
		Form f1("F1", 1, 1);
		Form f2("F2", 150, 150);
		std::cout << b1;
		std::cout << b2;
		std::cout << f1;
		std::cout << f2;
		b1.signForm(f1);
		b2.signForm(f2);
		b2.signForm(f1);
		b2.signForm(f2);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}