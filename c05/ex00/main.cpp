#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- Test 1: Valid Creation ---" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too High (0) ---" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grade Too Low (151) ---" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Increment Grade ---" << std::endl;
	try
	{
		Bureaucrat b("Bob", 50);
		std::cout << "Before: " << b << std::endl;
		b.incrementGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << "\n--- Test 5: Decrement Grade ---" << std::endl;
	try
	{
		Bureaucrat b("Alice", 50);
		std::cout << "Before: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After: " << b << std::endl;
		std::cout << b<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: Increment at Grade 1 (should throw) ---" << std::endl;
	try
	{
		Bureaucrat b("TopBureaucrat", 1);
		std::cout << "Before: " << b << std::endl;
		b.incrementGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test 7: Decrement at minimum (should throw)
	std::cout << "\n--- Test 7: Decrement at Grade 150 (should throw) ---" << std::endl;
	try
	{
		Bureaucrat b("BottomBureaucrat", 150);
		std::cout << "Before: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
