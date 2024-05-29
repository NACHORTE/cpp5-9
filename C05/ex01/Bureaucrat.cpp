#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		*const_cast<std::string *>(&_name) = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;

	}
}