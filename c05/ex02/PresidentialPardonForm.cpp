#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential",25,5){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
			:AForm::AForm(p),_target(p._target)
{
	std::cout << "Presidential copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	if (this != &p)
	{
		AForm::operator=(p);
		_target = p._target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
			:AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "Presidential param constructor called\n";
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getisSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getrequiredExec())
		throw AForm::GradeTooLowForExecException();
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
