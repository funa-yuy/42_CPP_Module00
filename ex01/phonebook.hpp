#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include "Contact.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

//電話帳 →連絡先が追加される
class PhoneBook {
	public:
		PhoneBook() : count(0), oldest(0) {}

		Contact	inputContact(void);
		void	addContact(const Contact& newContact);
		void	displayContactList();
		void	displayContact(size_t index);
	private:
		Contact	contacts[8];
		size_t	count;
		size_t	oldest;
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
