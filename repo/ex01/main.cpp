#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	entry;

	while (entry != "EXIT")
	{
		std::cout << "enter a command : ";
		if (!std::getline(std::cin, entry))
			return 0;
		if (entry == "ADD")
			phoneBook.addContact();
		else if (entry == "SEARCH")
			phoneBook.search();
	}
	return 0;
}
