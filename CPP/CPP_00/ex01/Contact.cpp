#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::m_getInput(std::string str)
{
	std::string input = "";
	bool valid = false;
	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	} while (!valid);
	return (input);
}

void Contact::start(void)
{
	this->m_firstName = this->m_getInput("Enter you first name: ");
	this->m_lastName = this->m_getInput("Enter your last name: ");
	this->m_nickName = this->m_getInput("Enter your nickname: ");
	this->m_phoneNumber = this->m_getInput("Enter your phone number: ");
	this->m_darkestSecret = this->m_getInput("Enter your darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::m_printLen(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::setIndex(int i)
{
	this->m_index = i;
}

void Contact::view(int index)
{
	if (this->m_firstName.empty() || this->m_lastName.empty() || this->m_nickName.empty())
		return;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->m_printLen(this->m_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->m_printLen(this->m_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->m_printLen(this->m_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void Contact::display(int index)
{
	if (this->m_firstName.empty() || this->m_lastName.empty() || this->m_nickName.empty())
	{
		std::cout << "The contact doesn't exist" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "CONTACT:\t" << index << std::endl;
	std::cout << "First Name:\t" << this->m_firstName << std::endl;
	std::cout << "Last Name:\t" << this->m_lastName << std::endl;
	std::cout << "Nickname:\t" << this->m_nickName << std::endl;
	std::cout << "Phone Number:\t" << this->m_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->m_darkestSecret << std::endl;

	std::cout << std::endl;
}