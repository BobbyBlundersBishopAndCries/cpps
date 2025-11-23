#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof())
			return 0;

		if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command." << std::endl;
	}

	return 0;
}
