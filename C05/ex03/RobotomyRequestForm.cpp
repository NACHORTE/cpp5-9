#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj)
{
	(void)obj;
	return (os);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getName() << " robotomization failed" << std::endl;
}