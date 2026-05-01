#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form():_isSigned(false), _requiredSign(1), _requiredExec(1)
{
	std::cout << "Default constructor with default values\n";
}

Form::~Form(){}

Form::Form(const Form& f):_formName(f._formName),_isSigned(f._isSigned),
		 _requiredSign(f._requiredSign), _requiredExec(f._requiredExec)
{
	std::cout << "Copy constructor Form\n";
}

Form& Form::operator=(const Form& f)
{	
	if(this != &f)
	{
		this->_formName = f._formName;
		this->_isSigned = f._isSigned;
		this->_requiredSign = f._requiredSign;
		this->_requiredExec = f._requiredExec;
	}
	std::cout << "Copy Assignement operator Form\n";
	return *this;
}

Form::Form(const std::string formName, int requiredSign, int requiredExec):
_formName(formName), _isSigned(false)
{
	if (requiredExec < 1 || requiredSign < 1)
		throw GradeTooHighException();
	else if (requiredExec > 150 || requiredSign > 150)
		throw GradeTooLowException();
	_requiredSign = requiredSign;
	_requiredExec = requiredExec;
	std::cout << "Parameterized Form constructor\n";
}

std::string Form::getFormName() const{return _formName;}
bool		Form::getisSigned()const{return _isSigned;}
int			Form::getrequiredSign()const{return _requiredSign;}
int			Form::getrequiredExec()const{return _requiredExec;}

const char *Form::GradeTooHighException::what()const throw()
{
	return "The form just cannot have a grade lower than 150";
}

const char *Form::GradeTooLowException::what()const throw()
{
	return "The form just cannot have a grade greater than 1";
}

void	Form::beSigned(Bureaucrat& b)
{
	if(b.getGrade() <= _requiredSign)
		_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form name: " << f.getFormName() 
		<< ", is Form signable ?: " << (f.getisSigned() ? "true" : "false")
		<< ", Form's required grade to sign: " << f.getrequiredSign()
		<< ", Form's required grade to execute: " << f.getrequiredExec() << std::endl;
	return out;	
}
