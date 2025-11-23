#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}
Contact::~Contact()
{
}
void Contact::setFirstname(const::std::string &first)
{
	firstname = first;
}
void Contact::setLastname(const::std::string &last)
{
	lastname = last;
}
void Contact::setNickname(const::std::string &nick)
{
	nickname = nick;
}
void Contact::setPhoneNumber(const::std::string &phone)
{
	phonenumber = phone;
}
void Contact::setDarkestSecret(const::std::string &dark)
{
	darkestsecret = dark;
}
std::string Contact::getFirstname() const { return firstname; }
std::string Contact::getLastname() const { return lastname; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phonenumber; }
std::string Contact::getDarkestSecret() const { return darkestsecret; }