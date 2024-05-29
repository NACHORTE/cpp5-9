#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execgrade) : _name(name), _signGrade(signGrade), _execGrade(execgrade), _isSigned(false)
{
	if (signGrade < 1 || execgrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execgrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		*const_cast<std::string *>(&_name) = rhs._name;
		*const_cast<int *>(&_signGrade) = rhs._signGrade;
		*const_cast<int *>(&_execGrade) = rhs._execGrade;
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return (_name);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

bool Form::getIsSigned(void) const
{
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (_isSigned)
		throw Form::FormAlreadySigned();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *Form::FormAlreadySigned::what() const throw()
{
	return ("Form is already signed.");
}

const char *Form::FormNotSigned::what() const throw()
{
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form " << obj.getName() << " requires grade " << obj.getSignGrade() << " to sign and grade " << obj.getExecGrade() << " to execute." << std::endl;
	return (os);
}
