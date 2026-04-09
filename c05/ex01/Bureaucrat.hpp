#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
class Form;
class Bureaucrat{
	private:
		std::string _name;
		int _grade;
	public:
		/* Orthodox Canonical Form */
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		/* Parameterized constructor */
		Bureaucrat(const std::string& name, int grade);
		/* getters */
		int getGrade() const;
		const std::string& getName() const;
		/* Increment Decrement grade*/
		void incrementGrade();
		void decrementGrade();
		/* exceptions */
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};		/* New function : signForm() */
		void	signForm(Form& f);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
#endif