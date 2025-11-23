#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
class Contact
{
private:
	std::string firstname;
	std::string lastname;
	std::string phonenumber;
	std::string nickname;
	std::string darkestsecret;
public:
    Contact();
    ~Contact();
    void setFirstname(const std::string &fn);
    void setLastname(const std::string &ln);
    void setNickname(const std::string &nn);
    void setPhoneNumber(const std::string &pn);
    void setDarkestSecret(const std::string &ds);
    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif