#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}