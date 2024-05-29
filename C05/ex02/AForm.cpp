#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execgrade) : _name(name), _signGrade(signGrade), _execGrade(execgrade), _isSigned(false)
{
	if (signGrade < 1 || execgrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execgrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
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

std::string AForm::getName(void) const
{
	return (_name);
}

int AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (_execGrade);
}

bool AForm::getIsSigned(void) const
{
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (_isSigned)
		throw AForm::FormAlreadySigned();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

const char *AForm::FormAlreadySigned::what() const throw()
{
	return ("Form is already signed.");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm " << obj.getName() << " requires grade " << obj.getSignGrade() << " to sign and grade " << obj.getExecGrade() << " to execute." << std::endl;
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
	if (!_isSigned)
		throw AForm::FormNotSigned();
}