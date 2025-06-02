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

class PhoneBook {
	public:
		PhoneBook();
		void	executeAdd();
		void	executeSearch();
		void	executeExit();

	private:
		Contact	contacts[8];
		size_t	count;
};

#endif
