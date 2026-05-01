#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main()
{	
	std::cout << "\n--- Test1: No exception should be thrown from here: ---\n";
	try
	{
		Bureaucrat best("Best", 1);
		std::cout << best << std::endl;
		Bureaucrat worst("Bottom", 150);
		worst.incrementGrade();
		std::cout << worst << std::endl;
		std::cout << "to here\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test2: Bureaucrat GradeTooHighException should be thrown from here: ---\n";
	try
	{
		Bureaucrat invalid("Invalid", 0);
		Bureaucrat highwannabe = invalid;
		std::cout << "--- to here ---\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test3: Bureaucrat GradeTooLowException should be thrown from here: ---\n";
	try
	{
		Bureaucrat invalid2("invalid2", 151);
		Bureaucrat lowwannabe = invalid2;
		std::cout << "--- to here ---\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test4: Sign form successfully ---\n";
	try
	{
		Bureaucrat best("Best", 1);
		Form topofhierachy("highest", 1, 1);
		best.signForm(topofhierachy);
		std::cout << "Form is signed: " << topofhierachy.getisSigned() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test5: Form GradeTooHighException should be thrown from here: ---\n";
	try
	{
		Form toohigh("toohigh", 0, 0);
		std::cout << "--- to here ---\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test6: Form GradeTooLowException should be thrown from here: ---\n";
	try
	{
		Form toolow("toolow", 177, 17);
		std::cout << "--- to here ---\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Form exception: " << e.what() << std::endl;
	}
	/* overloaded << operator */
	std::cout << "\n--- Test7: overloaded << operator ---\n";
	Bureaucrat best("Best", 1);
	std::cout << best << std::endl;
	Form topsecret("highest", 1, 1);
	std::cout << topsecret << std::endl;
	return 0;
}