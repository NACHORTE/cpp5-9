#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
	*this = rhs;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	size_t types = 3;
	for (size_t i = 0; i < types; i++)
	{
		if (formNames[i] == formName)
        {
			switch (i)
			{
                case 0:
                    return new RobotomyRequestForm(target);
                    break;
                case 1:
                    return new ShrubberyCreationForm(target);
                    break;
                case 2:
                    return new PresidentialPardonForm(target);
                    break;
                default:
                    std::cout << "Unexpected error" << std::endl;
                    return NULL;
            }
		}
	}
	std::cout << "Form not found" << std::endl;
	return NULL;
}