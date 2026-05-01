#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main()
{	
	std::cout << "\n===== CREATE BUREAUCRATS =====\n";
	Bureaucrat president;
	Bureaucrat manager;
	Bureaucrat new_b;
	try
	{
		president = Bureaucrat("President", 1);
		manager = Bureaucrat("Manager", 50);
		new_b = Bureaucrat("new_b", 150);
		std::cout << president << std::endl;
		std::cout << manager << std::endl;
		std::cout << new_b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception while creating bureaucrats: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n===== TEST SHRUBBERY FORM =====\n";
	try
	{
		ShruberryCreationForm shruberry("Garden");
		std::cout << shruberry;
		
		std::cout << "\n--- Signing shrubbery with President ---\n";
		president.signForm(shruberry);
		
		std::cout << "\n--- Executing shrubbery form ---\n";
		president.executeForm(shruberry);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Shrubbery test exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST ROBOTOMY FORM =====\n";
	try
	{
		RobotomyRequestForm robotomy("John");
		std::cout << robotomy;
		
		std::cout << "\n--- Signing robotomy with manager ---\n";
		manager.signForm(robotomy);
		
		std::cout << "\n--- Executing robotomy form (50% success) ---\n";
		manager.executeForm(robotomy);
		
		std::cout << "\n--- Execute again ---\n";
		manager.executeForm(robotomy);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Robotomy test exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST PRESIDENTIAL FORM =====\n";
	try
	{
		PresidentialPardonForm pardon("Criminal");
		std::cout << pardon;
		
		std::cout << "\n--- Trying to sign with manager (grade 50, needs 25) ---\n";
		manager.signForm(pardon);
		
		std::cout << "\n--- Signing with president (grade 1, needs 25) ---\n";
		president.signForm(pardon);
		
		std::cout << "\n--- Executing pardon form ---\n";
		president.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Presidential test exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== END OF TESTS =====\n";
	return 0;
}