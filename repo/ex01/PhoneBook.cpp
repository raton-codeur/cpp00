#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : _numContacts(0)
{
	std::cout << "phone book created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "phone book destroyed" << std::endl;
}

void PhoneBook::addContact()
{
	Contact	contact;
	int		i;

	i = this->_numContacts;
	if (this->_numContacts >= MAX_CONTACTS)
	{
		i = this->_numContacts % MAX_CONTACTS;
		std::cout << "warning : overwriting contact " << i + 1 << std::endl;
	}
	std::cout << "adding new contact" << std::endl;
	contact.fill();
	this->_contacts[i] = contact;
	this->_numContacts++;
}

static void printDashRow()
{
	int size = 4 * 10 + 4 + 1;
	for (int i = 0; i < size; i++)
		std::cout << "-";
	std::cout << std::endl;
}

static void printHeader()
{
	printDashRow();
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	printDashRow();
}

static void printField(const std::string& s)
{
	std::cout << "|";
	if (s.size() > 10)
		std::cout << s.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << s;
}

void PhoneBook::print() const
{
	printHeader();
	for (int i = 0; i < this->_numContacts && i < MAX_CONTACTS; i++)
	{
		printField(std::to_string(i + 1));
		printField(this->_contacts[i].getFirstName());
		printField(this->_contacts[i].getLastName());
		printField(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
		printDashRow();
	}
}

static bool str_is_digit(const std::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

void PhoneBook::search() const
{
	std::string	entry;
	int			i;

	if (this->_numContacts == 0)
	{
		std::cout << "no contacts" << std::endl;
		return;
	}
	this->print();
	while (true)
	{
		std::cout << "index : ";
		std::getline(std::cin, entry);
		i = std::atoi(entry.c_str());
		if (!str_is_digit(entry) || i < 1 || i > this->_numContacts || i > MAX_CONTACTS)
			std::cout << "invalid index" << std::endl;
		else
		{
			this->_contacts[i - 1].print();
			break;
		}
	}
}
