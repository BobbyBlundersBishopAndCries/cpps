#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy",72,45){}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
			:AForm::AForm(r),_target(r._target)
{
	std::cout << "Robotomy copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	if (this != &r)
	{
		AForm::operator=(r);
		_target = r._target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
			:AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "Robotomy param constructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getisSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getrequiredExec())
		throw AForm::GradeTooLowForExecException();
	
	std::cout << "* BZZZZZZZZZZZZZZZZZZZZZZ *\n";
	
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << _target << "\n";
}
