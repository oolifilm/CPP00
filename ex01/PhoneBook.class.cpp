/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:23:52 by leaugust          #+#    #+#             */
/*   Updated: 2025/07/26 17:43:22 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
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
		contacts[i].displayContact(i);
	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	int index = input[0] - '1';

	if (index >= totalContacts)
	{
		std::cout << "No contact at this index." << std::endl;
		return ;
	}
	contacts[index].displayDetails();
}
