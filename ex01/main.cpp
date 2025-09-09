/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:19:48 by leaugust          #+#    #+#             */
/*   Updated: 2025/08/28 19:06:59 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.class.hpp"
#include <csignal>


void handle_sigquit(int sig) {
    std::cout << std::endl << "Signal " << sig << " (Ctrl-\\) detected. Aborting." << std::endl;
    std::exit(0);
}


int main() {
    std::signal(SIGQUIT, handle_sigquit);
    PhoneBook phoneBook;
    std::string command;

    while(true)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (!std::cin)
        {
            std::cout << std::endl << "Input interrupted. Aborting." << std::endl;
            exit(0);
        }
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