#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm():_isSigned(false), _requiredSign(1), _requiredExec(1)
{
	std::cout << "Default Aform constructor with default values\n";
}

AForm::~AForm()
{
	std::cout << "AForm to the dump\n";
}

AForm::AForm(const AForm& f):_formName(f._formName),_isSigned(f._isSigned),
		 _requiredSign(f._requiredSign), _requiredExec(f._requiredExec)
{
	std::cout << "Copy constructor AForm\n";
}

AForm& AForm::operator=(const AForm& f)
{	
	if(this != &f)
	{
		this->_formName = f._formName;
		this->_isSigned = f._isSigned;
		this->_requiredSign = f._requiredSign;
		this->_requiredExec = f._requiredExec;
	}
	std::cout << "Copy Assignement operator AForm\n";
	return *this;
}

AForm::AForm(const std::string formName, int requiredSign, int requiredExec):
_formName(formName), _isSigned(false)
{
	if (requiredExec < 1 || requiredSign < 1)
		throw GradeTooHighException();
	else if (requiredExec > 150 || requiredSign > 150)
		throw GradeTooLowException();
	_requiredSign = requiredSign;
	_requiredExec = requiredExec;
	std::cout << "Parameterized AForm constructor\n";
}

std::string AForm::getFormName() const{return _formName;}
bool		AForm::getisSigned()const{return _isSigned;}
int			AForm::getrequiredSign()const{return _requiredSign;}
int			AForm::getrequiredExec()const{return _requiredExec;}

const char *AForm::GradeTooHighException::what()const throw()
{
	return "The form just cannot have a grade lower than 150";
}

const char *AForm::GradeTooLowException::what()const throw()
{
	return "The form just cannot have a grade greater than 1";
}

const char *AForm::FormNotSignedException::what()const throw()
{
	return "Form is not signed";
}

const char *AForm::GradeTooLowForExecException::what()const throw()
{
					return "Grade is too low to execute";
}

void	AForm::beSigned(Bureaucrat& b)
{
	if(b.getGrade() <= _requiredSign)
		_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << "AForm name: " << f.getFormName() 
		<< ", is AForm signable ?: " << f.getisSigned()
		<< ", AForm's required grade to sign: " << f.getrequiredSign()
		<< ", AForm's required grade to execute: " << f.getrequiredExec() << std::endl;
	return out;	
}
