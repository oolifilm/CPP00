/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:10:38 by leaugust          #+#    #+#             */
/*   Updated: 2025/07/26 17:22:36 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

# define BOLD "\033[1m"
# define RESET "\033[0m"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	void addContact();
	void searchContact() const;

  private:
	Contact contacts[8];
	int totalContacts;
	int oldestIndex;
};

#endif