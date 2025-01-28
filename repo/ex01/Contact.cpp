#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() :
	_firstName("NO VALUE"),
	_lastName("NO VALUE"),
	_nickname("NO VALUE"),
	_phoneNumber("NO VALUE"),
	_darkestSecret("NO VALUE")
{}

const std::string& Contact::getFirstName() const
{
	return this->_firstName;
}

const std::string& Contact::getLastName() const
{
	return this->_lastName;
}

const std::string& Contact::getNickname() const
{
	return this->_nickname;
}

const std::string& Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

const std::string& Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

static bool isBlank(const std::string& s)
{
	if (s.empty())
		return true;
    for (size_t i = 0; i < s.size(); i++)
	{
        if (!std::isspace(s[i]))
            return false;
    }
    return true;
}

static void get(std::string& field)
{
	std::string	entry;

	std::getline(std::cin, entry);
	if (std::cin.eof())
		exit(0);
	if (!isBlank(entry))
		field = entry;
}

void Contact::fill()
{
	std::cout << "first name : ";
	get(this->_firstName);
	std::cout << "last name : ";
	get(this->_lastName);
	std::cout << "nickname : ";
	get(this->_nickname);
	std::cout << "phone number : ";
	get(this->_phoneNumber);
	std::cout << "darkest secret : ";
	get(this->_darkestSecret);
}

void Contact::print() const
{
	std::cout << "first name : " << this->_firstName << std::endl;
	std::cout << "last name : " << this->_lastName << std::endl;
	std::cout << "nickname : " << this->_nickname << std::endl;
	std::cout << "phone number : " << this->_phoneNumber << std::endl;
	std::cout << "darkest secret : " << this->_darkestSecret << std::endl;
}
