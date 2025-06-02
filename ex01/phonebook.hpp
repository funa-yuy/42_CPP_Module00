#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>


// ------------------------------------------------
// class
// ------------------------------------------------

//連絡先
class Contact {
public:
	std::string f_name;	// 名
	std::string l_name;	// 姓
	std::string n_name;	// ニックネーム
	std::string phone_number;	// 電話番号
	std::string darkest_secret;	// 暗闇の秘密
};

//電話帳 →連絡先が追加される
class PhoneBook {
public:
	PhoneBook() : count(0), oldest(0) {}

	void	addContact(const Contact& newContact) {
		size_t	index;

		if (count < 8)
			index = count;
		else
			index = oldest;
		contacts[index] = newContact;
		if (count < 8)
			count++;
		oldest = (oldest + 1) % 8;
	}
	void	display_PhoneBook() {
		std::cout << "|" << std::setw(10) << "Index" << "|"
					<< std::setw(10) << "First Name" << "|"
					<< std::setw(10) << "Last Name" << "|"
					<< std::setw(10) << "Nickname" << "|" << std::endl;
					std::cout << "|----------|----------|----------|----------|" << std::endl;

		for (size_t i = 0; i < 8 && i < count; i++) {
			std::cout << "|" << std::setw(10) << i << "|"
					<< std::setw(10) << contacts[i].f_name << "|"
					<< std::setw(10) << contacts[i].l_name << "|"
					<< std::setw(10) << contacts[i].n_name << "|" << std::endl;
		}
	}
private:
	Contact	contacts[8];
	size_t	count;
	size_t	oldest;
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
