#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : number(0), oldest(0) {}

PhoneBook::~PhoneBook() {}

static bool isValid(const std::string &s)
{
    if (s.empty())
        return false;

    for (std::string::size_type i = 0; i < s.length(); i++)
    {
        if (!std::isspace(s[i]))
            return true;
    }
    return false;
}


void PhoneBook::AddContact()
{
    std::string input;

    int index = (number < 8) ? number : oldest;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    if (!isValid(input)) { std::cout << "Invalid input.\n"; return; }
    contacts[index].setFirstname(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    if (!isValid(input)) { std::cout << "Invalid input.\n"; return; }
    contacts[index].setLastname(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    if (!isValid(input)) { std::cout << "Invalid input.\n"; return; }
    contacts[index].setNickname(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    if (!isValid(input)) { std::cout << "Invalid input.\n"; return; }
    contacts[index].setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    if (!isValid(input)) { std::cout << "Invalid input.\n"; return; }
    contacts[index].setDarkestSecret(input);

    std::cout << "Contact added successfully.\n";

    if (number < 8)
        number++;
    else
        oldest = (oldest + 1) % 8;
}


void PhoneBook::DisplayInfo(int index)
{
	if (index < 0 || index >= number)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstname() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastname() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

static std::string FormatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::SearchContact() const
{
	if (number == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index"     << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name"  << "|"
	          << std::setw(10) << "Nickname"   << std::endl;

	int i = 0;
	while(i < number)
	{
		std::cout << std::setw(10) << i << "|"
		          << std::setw(10) << FormatField(contacts[i].getFirstname()) << "|"
		          << std::setw(10) << FormatField(contacts[i].getLastname())  << "|"
		          << std::setw(10) << FormatField(contacts[i].getNickname())   << std::endl;
		i++;
	}
	std::cout << "Enter an index to display: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid input." << std::endl;
		return;
	}
	int index = input[0] - '0';
	if (index < 0 || index >= number)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "---- Contact Info ----" << std::endl;
	std::cout << "First Name: "     << contacts[index].getFirstname()     << std::endl;
	std::cout << "Last Name: "      << contacts[index].getLastname()      << std::endl;
	std::cout << "Nickname: "       << contacts[index].getNickname()       << std::endl;
	std::cout << "Phone Number: "   << contacts[index].getPhoneNumber()   << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
