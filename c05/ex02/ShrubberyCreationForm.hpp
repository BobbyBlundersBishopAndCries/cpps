#ifndef SHRUBERRYCREATIONFORM_HPP
#define  SHRUBERRYCREATIONFORM_HPP
#include "AForm.hpp"

class ShruberryCreationForm: public AForm {
	std::string _target;
	public:
		/* Orthodox cannonical form */
		ShruberryCreationForm();
		~ShruberryCreationForm();
		ShruberryCreationForm& operator=(const ShruberryCreationForm& s);
		ShruberryCreationForm(const ShruberryCreationForm& s);
		/* Param constructor */
		ShruberryCreationForm(const std::string& target);
		/* Function to implement */
		void	execute(Bureaucrat const & executor) const;
};
#endif