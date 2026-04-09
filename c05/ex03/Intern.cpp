#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

/* Helper functions to create forms */
static AForm* createShrubbery(const std::string& target)
{
	return new ShruberryCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

typedef AForm* (*FormCreator)(const std::string&);

AForm* Intern::makeForm(const std::string& formname, const std::string& target)
{
	/* Arrays mapping form names to creator functions */
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormCreator creators[3] = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	/* Loop through to find the matching form */
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formname)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return creators[i](target);
		}
	}

	/* Form not found */
	std::cout << "Error: form type \"" << formname << "\" does not exist" << std::endl;
	return NULL;
}
