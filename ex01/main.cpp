/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:19:48 by leaugust          #+#    #+#             */
/*   Updated: 2025/07/26 13:54:44 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

int main() {
    
    PhoneBook phoneBook;
    std::string command;

    while(true)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if(command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command. Please try again." << std::endl;
    }
    return 0;
}