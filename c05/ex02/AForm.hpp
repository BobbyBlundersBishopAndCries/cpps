#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
class Bureaucrat;

class AForm {
	private:
		std::string _formName;
		bool		_isSigned;
		int			_requiredSign;
		int			_requiredExec;
	public:
		/* Orthodox connonical form */
		AForm();
		virtual ~AForm();
		AForm(const AForm& f);
		AForm& operator=(const AForm& f);
		/*Parameterized constructor*/
		AForm(const std::string formName, int requiredSign, int requiredExec);
		/* getters */
		std::string getFormName() const;
		bool		getisSigned()const;
		int			getrequiredSign()const;
		int			getrequiredExec()const;
		/* Exceptions */
		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowForExecException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		/* ex02 functions */
		void	beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};
/* Operator << overloading */
std::ostream& operator<<(std::ostream& out, const AForm& f);
#endif