#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{	
	std::cout << "\n===== CREATE BUREAUCRATS =====\n";
	Bureaucrat president("President", 1);
	Bureaucrat manager("Manager", 50);
	std::cout << president << std::endl;
	std::cout << manager << std::endl;

	std::cout << "\n===== INTERN CREATES FORMS =====\n";
	Intern intern;

	std::cout << "\n--- Creating Shrubbery Form ---\n";
	AForm *shrubbery = intern.makeForm("shrubbery creation", "Garden");
	if (shrubbery)
	{
		std::cout << *shrubbery;
		president.signForm(*shrubbery);
		president.executeForm(*shrubbery);
		delete shrubbery;
	}

	std::cout << "\n--- Creating Robotomy Form ---\n";
	AForm *robotomy = intern.makeForm("robotomy request", "Bender");
	if (robotomy)
	{
		std::cout << *robotomy;
		manager.signForm(*robotomy);
		manager.executeForm(*robotomy);
		delete robotomy;
	}

	std::cout << "\n--- Creating Presidential Form ---\n";
	AForm *pardon = intern.makeForm("presidential pardon", "Criminal");
	if (pardon)
	{
		std::cout << *pardon;
		president.signForm(*pardon);
		president.executeForm(*pardon);
		delete pardon;
	}

	std::cout << "\n--- Trying to create invalid form ---\n";
	AForm *invalid = intern.makeForm("invalid form", "nobody");
	if (invalid)
	{
		delete invalid;
	}

	std::cout << "\n===== END OF TESTS =====\n";
	return 0;
}