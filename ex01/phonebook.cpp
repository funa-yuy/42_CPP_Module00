#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {}

// PhoneBook::executeAdd ---------------------------------------------

Contact	inputContact() {
	Contact	newContact;
	std::string	tmp;

	std::cout << "First name: ";
	std::cin >> tmp;
	newContact.setInfo(Contact::F_name, tmp);
	std::cout << "Last name: ";
	std::cin >> tmp;
	newContact.setInfo(Contact::L_name, tmp);
	std::cout << "Nickname: ";
	std::cin >> tmp;
	newContact.setInfo(Contact::N_name, tmp);
	std::cout << "Phone number: ";
	std::cin >> tmp;
	newContact.setInfo(Contact::Phone_number, tmp);
	std::cout << "Darkest secret: ";
	std::cin >> tmp;
	newContact.setInfo(Contact::Darkest_secret, tmp);

	return (newContact);
}

void	PhoneBook::executeAdd() {
	Contact	newContact;

	/* 標準入力から連絡先を所得し、 返す */
	newContact = inputContact();

	/* 所定のindexに保存 */
	contacts[count % 8] = newContact;
	count++;
}


// PhoneBook::executeSearch ------------------------------------------

void	displayContactList(Contact contacts[8], size_t count) {
	//見出し表示
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;

	//保存されてる全ての連絡先を表示
	for (size_t i = 0; i < 8 && i < count; i++) {
		std::cout << "|" << std::setw(10) << i << "|"
				<< std::setw(10) << contacts[i].getInfo(Contact::F_name) << "|"
				<< std::setw(10) << contacts[i].getInfo(Contact::L_name) << "|"
				<< std::setw(10) << contacts[i].getInfo(Contact::N_name) << "|" << std::endl;
	}
}

int	inputIndex() {
	std::string	index;

	std::cout << "index: ";
	std::cin >> index;
	if (index.length() > 3)
		return (-1);
	if (std::all_of(index.cbegin(), index.cend(), isdigit))
		return (std::stoi(index));
	return (-1);
}

void	displayContact(Contact contacts[8], size_t count, size_t index) {
	//indexが、0以下、7以上、countよりも大きい場合は不正処理
	if (index < 0 || index > 7 || index >= count)
	{
		std::cout << "Error: Index is out of range or incorrect." << std::endl;;
		return ;
	}

	std::cout << "Index: "<< index << std::endl;
	std::cout << "First name: "<< contacts[index].getInfo(Contact::F_name) << std::endl;
	std::cout << "Last name: " << contacts[index].getInfo(Contact::L_name) << std::endl;
	std::cout << "Nickname: " << contacts[index].getInfo(Contact::N_name) << std::endl;
	std::cout << "Phone numbe: " << contacts[index].getInfo(Contact::Phone_number) << std::endl;
	std::cout << "Darkest secre: " << contacts[index].getInfo(Contact::Darkest_secret) << std::endl;
}

void	PhoneBook::executeSearch() {
	int	index;

	/* 電話帳を表示 */
	displayContactList(contacts, count);

	/* 標準入力からindexを取得 & 間違った値であれば-1を返す */
	index = inputIndex();

	/* indexで指定された連絡先を表示 */
	displayContact(contacts, count, index);
}


// PhoneBook::executeExit ---------------------------------------------

void	PhoneBook::executeExit() {
	std::exit(EXIT_SUCCESS);
}

// ------------------------------------------------------------------
