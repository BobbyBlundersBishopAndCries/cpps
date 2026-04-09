#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm():AForm("ShrubberyType",145,137){}

ShruberryCreationForm::~ShruberryCreationForm()
{
	std::cout << "Shruberry destructor called\n";
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& s)
			:AForm::AForm(s),_target(s._target)
{
	std::cout << "Shruberry copy constructor called\n";
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& s)
{
	if (this != &s)
	{
		AForm::operator=(s);
		_target = s._target;
	}
	return *this;
}

ShruberryCreationForm::ShruberryCreationForm(const std::string& target)
			:AForm("ShrubberyType", 145, 137), _target(target)
{
	std::cout << "Shrubbery 's param constructor called\n";
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getisSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getrequiredExec())
		throw AForm::GradeTooLowForExecException();
	std::ofstream file((_target + "_shruberry").c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to create file");
	file << "    *    \n";
	file << "   ***   \n";
	file << "  *****  \n";
	file << " ******* \n";
	file << " *  *  * \n";
	file << "   ***   \n";
	file << "  *****  \n";
}

