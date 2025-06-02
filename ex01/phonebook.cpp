#include "PhoneBook.hpp"

/* 連絡先の情報を入力し、newContactを返す */
Contact	PhoneBook::inputContact() {
		Contact	newContact;

		std::cout << "First name: ";
		std::cin >> newContact.f_name;
		std::cout << "Last name: ";
		std::cin >> newContact.l_name;
		std::cout << "Nickname: ";
		std::cin >> newContact.n_name;
		std::cout << "Phone numbe: ";
		std::cin >> newContact.phone_number;
		std::cout << "Darkest secre: ";
		std::cin >> newContact.darkest_secret;
		return (newContact);
}

/* newContactを、contactsに追加 */
void	PhoneBook::addContact(const Contact& newContact) {
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

/* 保存されてる全ての連絡先を表示する */
void	PhoneBook::displayContactList() {
	//見出し表示
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;

	//保存されてる全ての連絡先を表示
	for (size_t i = 0; i < 8 && i < count; i++) {
		//与えられた引数を、指定されたフォーマットで表示

		std::cout << "|" << std::setw(10) << i << "|"
				<< std::setw(10) << contacts[i].f_name << "|"
				<< std::setw(10) << contacts[i].l_name << "|"
				<< std::setw(10) << contacts[i].n_name << "|" << std::endl;
	}
}

/* indexで指定された連絡先を表示 */
void	PhoneBook::displayContact(size_t index) {
	if (index > 8 || index >= count)
	{
		std::cout << "Index is out of range or incorrect." << std::endl;;
		return ;
	}
	std::cout << "First name: "<< contacts[index].f_name << std::endl;
	std::cout << "Last name: " << contacts[index].l_name << std::endl;
	std::cout << "Nickname: " << contacts[index].n_name << std::endl;
	std::cout << "Phone numbe: " << contacts[index].phone_number << std::endl;
	std::cout << "Darkest secre: " << contacts[index].darkest_secret << std::endl;
}
