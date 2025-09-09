/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:23:52 by leaugust          #+#    #+#             */
/*   Updated: 2025/08/28 19:01:45 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::addContact()
{
	if (totalContacts < 8)
		contacts[totalContacts++].setContact();
	else
	{
		contacts[oldestIndex].setContact();
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully !" << std::endl;
}

void PhoneBook::searchContact() const
{
	if (totalContacts == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname" << std::endl;

	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < totalContacts && i < 8; ++i)
	{
		std::cout << std::setw(10) 
		<< (i + 1) << "|" << std::setw(10) 
		<< formatField(contacts[i].getFirstName()) 
		<< "|" << std::setw(10) << formatField(contacts[i].getLastName()) 
		<< "|" << std::setw(10) << formatField(contacts[i].getNickname()) 
		<< std::endl;
	}
	std::string input;
	int index;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, input);
		if (!std::cin)
        {
            std::cout << std::endl << "Input interrupted. Aborting." << std::endl;
            exit(0);
        }
		if (input.length() != 1 || input[0] < '1' || input[0] > '8')
		{
			std::cout << "Invalid index. Please try again." << std::endl;
			continue ;
		}
		index = input[0] - '1';
		if (index >= totalContacts)
		{
			std::cout << "No contact at this index. Please try again." << std::endl;
			continue ;
		}
		break ;
	}
	contacts[index].displayDetails();
}
