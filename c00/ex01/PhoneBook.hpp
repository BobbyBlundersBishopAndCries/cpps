#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
	Contact contacts[8];
	int number;
	int oldest;

	public:
	PhoneBook();
	~PhoneBook(); 
	void AddContact();
	void SearchContact()const;
	void DisplayInfo(int index);
};
#endif