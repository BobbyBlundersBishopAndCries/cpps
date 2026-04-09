#ifndef FORM_HPP
#define FORM_HPP
#include <string>
class Bureaucrat;

class Form {
	private:
		std::string _formName;
		bool		_isSigned;
		int			_requiredSign;
		int			_requiredExec;
	public:
		/* Orthodox connonical form */
		Form();
		~Form();
		Form(const Form& f);
		Form& operator=(const Form& f);
		/*Parameterized constructor*/
		Form(const std::string formName, int requiredSign, int requiredExec);
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
		/* beSigned */
		void	beSigned(Bureaucrat& b);
};
/* Operator << overloading */
std::ostream& operator<<(std::ostream& out, const Form& f);
#endif