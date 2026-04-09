#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	std::string _target;
	public:
		/* Orthodox cannonical form */
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
		PresidentialPardonForm(const PresidentialPardonForm& p);
		/* Param constructor */
		PresidentialPardonForm(const std::string& target);
		/* Function to implement */
		void	execute(Bureaucrat const & executor) const;
};
#endif