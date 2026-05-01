#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

int main()
{	
	std::cout << "\n===== CREATE BUREAUCRATS =====\n";
	Bureaucrat president;
	Bureaucrat manager;
	try
	{
		president = Bureaucrat("President", 1);
		manager = Bureaucrat("Manager", 50);
		std::cout << president << std::endl;
		std::cout << manager << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INTERN CREATES FORMS =====\n";
	Intern intern;

	std::cout << "\n--- Creating Shrubbery Form ---\n";
	AForm *shrubbery = NULL;
	try
	{
		shrubbery = intern.makeForm("shrubbery creation", "Garden");
		if (shrubbery)
		{
			std::cout << *shrubbery;
			president.signForm(*shrubbery);
			president.executeForm(*shrubbery);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Shrubbery exception: " << e.what() << std::endl;
	}
	delete shrubbery;
	shrubbery = NULL;

	std::cout << "\n--- Creating Robotomy Form ---\n";
	AForm *robotomy = NULL;
	try
	{
		robotomy = intern.makeForm("robotomy request", "Bender");
		if (robotomy)
		{
			std::cout << *robotomy;
			manager.signForm(*robotomy);
			manager.executeForm(*robotomy);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Robotomy exception: " << e.what() << std::endl;
	}
	delete robotomy;
	robotomy = NULL;

	std::cout << "\n--- Creating Presidential Form ---\n";
	AForm *pardon = NULL;
	try
	{
		pardon = intern.makeForm("presidential pardon", "Criminal");
		if (pardon)
		{
			std::cout << *pardon;
			president.signForm(*pardon);
			president.executeForm(*pardon);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Presidential exception: " << e.what() << std::endl;
	}
	delete pardon;
	pardon = NULL;

	std::cout << "\n--- Trying to create invalid form ---\n";
	AForm *invalid = NULL;
	try
	{
		invalid = intern.makeForm("invalid form", "nobody");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Intern exception: " << e.what() << std::endl;
	}
	delete invalid;
	invalid = NULL;

	std::cout << "\n===== END OF TESTS =====\n";
	return 0;
}