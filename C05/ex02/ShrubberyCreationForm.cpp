#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << std::endl;
		file.close();
	}
	else
	{
		throw ShrubberyCreationForm::FileError();
	}
}

const char * ShrubberyCreationForm::FileError::what() const throw()
{
	return ("Error opening file");
}
