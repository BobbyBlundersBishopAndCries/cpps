#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	std::string _target;
	public:
		/* Orthodox cannonical form */
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		/* Param constructor */
		RobotomyRequestForm(const std::string& target);
		/* Function to implement */
		void	execute(Bureaucrat const & executor) const;
};
#endif
