#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern Me;
	Bureaucrat boss(2, "boss");

	AForm *form = Me.makeForm("presidential pardon", "pardoned");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n";


	form = Me.makeForm("wrong", "wrongest");
	std::cout << "\n";

	form = Me.makeForm("robotomy request", "robot");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	std::cout << "\n";


	form = Me.makeForm("shrubbery creation", "shrubs");
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
	return 0;
}