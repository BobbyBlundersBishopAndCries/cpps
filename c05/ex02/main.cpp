#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{	
	std::cout << "\n===== CREATE BUREAUCRATS =====\n";
	Bureaucrat president("President", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat intern("Intern", 150);
	std::cout << president << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n===== TEST SHRUBBERY FORM =====\n";
	ShruberryCreationForm shruberry("Garden");
	std::cout << shruberry;
	
	std::cout << "\n--- Signing shrubbery with President ---\n";
	president.signForm(shruberry);
	
	std::cout << "\n--- Executing shrubbery form ---\n";
	president.executeForm(shruberry);

	std::cout << "\n===== TEST ROBOTOMY FORM =====\n";
	RobotomyRequestForm robotomy("John");
	std::cout << robotomy;
	
	std::cout << "\n--- Signing robotomy with manager ---\n";
	manager.signForm(robotomy);
	
	std::cout << "\n--- Executing robotomy form (50% success) ---\n";
	manager.executeForm(robotomy);
	
	std::cout << "\n--- Execute again ---\n";
	manager.executeForm(robotomy);

	std::cout << "\n===== TEST PRESIDENTIAL FORM =====\n";
	PresidentialPardonForm pardon("Criminal");
	std::cout << pardon;
	
	std::cout << "\n--- Trying to sign with manager (grade 50, needs 25) ---\n";
	manager.signForm(pardon);
	
	std::cout << "\n--- Signing with president (grade 1, needs 25) ---\n";
	president.signForm(pardon);
	
	std::cout << "\n--- Executing pardon form ---\n";
	president.executeForm(pardon);

	std::cout << "\n===== END OF TESTS =====\n";
	return 0;
}