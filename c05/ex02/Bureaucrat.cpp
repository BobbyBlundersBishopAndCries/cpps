#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){_grade = 1;}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name),_grade(other._grade)
{
	std::cout << "Created by copy constructor\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
	{
		_grade = other._grade;
		_name = other._name;
	}	
	std::cout << "Assgned vals by assignement operator\n";
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
	_name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Param constructor with exception handling\n";
}

int Bureaucrat::getGrade()const {return _grade;}
const std::string& Bureaucrat::getName()const {return _name;}

void	Bureaucrat::incrementGrade()
{
	if(_grade == 1)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if(_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high and should not be < 1\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low and should not be > 150\n";
}

void	Bureaucrat::signForm(AForm& f)
{
	f.beSigned(*this);
	if (f.getisSigned() == true)
		std::cout << _name << " singed " << f.getFormName();
	else
		std::cout << _name << " couldn't sign " << f.getFormName() << " because "
		<< "Lower grade to the form\n";
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getFormName() << std::endl;
    }
    catch (const AForm::FormNotSignedException& e)
    {
        std::cout << _name << " couldn't execute " << form.getFormName() 
                  << " because " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowForExecException& e)
    {
        std::cout << _name << " couldn't execute " << form.getFormName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}