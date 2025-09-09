/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:33:52 by leaugust          #+#    #+#             */
/*   Updated: 2025/08/28 19:01:38 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <cstdlib>


Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

static std::string promptInput(const std::string &fieldName)
{
	std::string input;
	while (true)
	{
		std::cout << fieldName;
		std::getline(std::cin, input);
		if (!std::cin)
        {
            std::cout << std::endl << "Input interrupted. Aborting." << std::endl;
            exit(0);
        }
		if (!input.empty())
			return (input);
		std::cout << "This field can't be empty. Please enter a value." << std::endl;
	}
}

static std::string promptName(const std::string &fieldName)
{
	char	c;
	size_t	i;

	std::string input;
	while (true)
	{
		std::cout << fieldName;
		std::getline(std::cin, input);
		if (!std::cin)
        {
            std::cout << std::endl << "Input interrupted. Aborting." << std::endl;
            exit(0);
        }
		if (input.empty())
		{
			std::cout << "This field can't be empty. Please enter a value." << std::endl;
			continue ;
		}
		i = 0;
		for (; i < input.length(); ++i)
		{
			c = input[i];
			if (!std::isalpha(c) && c != ' ' && c != '-')
			{
				std::cout << "Invalid name. Use only letters, spaces or hyphens." << std::endl;
				break ;
			}
		}
		if (i == input.length())
			return (input);
	}
}

static std::string promptPhoneNumber(const std::string &fieldName)
{
	std::string input;
	while (true)
	{
		std::cout << fieldName;
		std::getline(std::cin, input);
		if (!std::cin)
        {
            std::cout << std::endl << "Input interrupted. Aborting." << std::endl;
            exit(0);
        }
		if (input.length() == 10 && input[0] == '0'
			&& input.find_first_not_of("0123456789") == std::string::npos)
			return (input);
		std::cout << "Invalid phone number. It must be exactly 10 digits and start with 0." << std::endl;
	}
}

static std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void Contact::setContact()
{
	_firstName = promptName("First name: ");
	_lastName = promptName("Last name: ");
	_nickname = promptInput("Nickname: ");
	_phoneNumber = promptPhoneNumber("Phone number: ");
	_darkestSecret = promptInput("Darkest secret: ");
}

void Contact::displayContact(int index) const
{
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << formatField(_firstName) << "|" << formatField(_lastName) << "|" << formatField(_nickname) << std::endl;
}

void Contact::displayDetails() const
{
    std::cout << "First name: " << getFirstName() << std::endl;
    std::cout << "Last name: " << getLastName() << std::endl;
    std::cout << "Nickname: " << getNickname() << std::endl;
    std::cout << "Phone number: " << getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << getDarkestSecret() << std::endl;
}
