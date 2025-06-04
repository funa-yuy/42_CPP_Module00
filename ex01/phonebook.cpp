#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count_(0) {}

bool isBlankLine(const std::string& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (!std::isspace(static_cast<unsigned char>(s[i]))) {
			return (false);
		}
	}
	return (true);
}

std::string	getStrLine()
{
	std::string	s;

	while (isBlankLine(s)) {
		std::getline(std::cin, s);
	}
	return (s);
}

// PhoneBook::executeAdd ---------------------------------------------

Contact	inputContact() {
	Contact	newContact;
	std::string	tmp;

	std::cout << "First name: ";
	newContact.setInfo(Contact::F_name, getStrLine());
	std::cout << "Last name: ";
	newContact.setInfo(Contact::L_name, getStrLine());
	std::cout << "Nickname: ";
	newContact.setInfo(Contact::N_name, getStrLine());
	std::cout << "Phone number: ";
	newContact.setInfo(Contact::Phone_number, getStrLine());
	std::cout << "Darkest secret: ";
	newContact.setInfo(Contact::Darkest_secret, getStrLine());

	return (newContact);
}

void	PhoneBook::executeAdd() {
	Contact	newContact;

	/* 標準入力から連絡先を所得し、 返す */
	newContact = inputContact();

	/* 所定のindexに保存 */
	book_[count_ % 8] = newContact;
	count_++;
}


// PhoneBook::executeSearch ------------------------------------------

std::string	truncatesStrTo10(std::string str)
{
	if (str.length() >= 10)
	{
		str = str.erase(9);
		str.push_back('.');
	}
	return (str);
}

void	displayContactList(Contact book_[8], int count_) {
	//見出し表示
	std::cout << "|"
			<< std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	//保存されてる全ての連絡先を表示
	for (int i = 0; i < 8 && i < count_; i++) {
		std::cout << "|"
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncatesStrTo10(book_[i].getInfo(Contact::F_name)) << "|"
			<< std::setw(10) << truncatesStrTo10(book_[i].getInfo(Contact::L_name)) << "|"
			<< std::setw(10) << truncatesStrTo10(book_[i].getInfo(Contact::N_name)) << "|" << std::endl;
	}
}

int	inputIndex() {
	std::string	index;

	std::cout << "index: ";
	index = getStrLine();
	if (index.length() > 3)
		return (-1);
	if (std::all_of(index.cbegin(), index.cend(), isdigit))
		return (std::stoi(index));
	return (-1);
}

void	displayContact(Contact book_[8], int count_, int index) {
	//indexが、0以下、7以上、count_よりも大きい場合は不正処理
	if (index < 0 || index > 7 || index >= count_)
	{
		std::cout << "Error: Index is out of range or incorrect." << std::endl;;
		return ;
	}

	std::cout << "Index: "<< index << std::endl;
	std::cout << "First name: "<< book_[index].getInfo(Contact::F_name) << std::endl;
	std::cout << "Last name: " << book_[index].getInfo(Contact::L_name) << std::endl;
	std::cout << "Nickname: " << book_[index].getInfo(Contact::N_name) << std::endl;
	std::cout << "Phone numbe: " << book_[index].getInfo(Contact::Phone_number) << std::endl;
	std::cout << "Darkest secre: " << book_[index].getInfo(Contact::Darkest_secret) << std::endl;
}

void	PhoneBook::executeSearch() {
	int	index;

	/* 電話帳を表示 */
	displayContactList(book_, count_);

	/* 標準入力からindexを取得 & 間違った値であれば-1を返す */
	index = inputIndex();

	/* indexで指定された連絡先を表示 */
	displayContact(book_, count_, index);
}


// PhoneBook::executeExit ---------------------------------------------

void	PhoneBook::executeExit() {
	std::exit(EXIT_SUCCESS);
}

// ------------------------------------------------------------------
