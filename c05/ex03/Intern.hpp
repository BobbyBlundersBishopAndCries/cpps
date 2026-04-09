#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		AForm *makeForm(const std::string& formname, const std::string& target);
};
#endif