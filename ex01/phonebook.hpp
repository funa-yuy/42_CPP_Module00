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
		PhoneBook();
		void	executeAdd();
		void	executeSearch();
		void	executeExit();

	private:
		Contact	contacts[8];
		size_t	count;
};

#endif
