
#include "phonebook.hpp"

void	executeAdd(PhoneBook& p)
{
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
	p.addContact(newContact);
}

void	executeSearch(PhoneBook& p)
{
	std::cout << "SEARCH" <<std::endl;
	p.display_PhoneBook();
}

void	executeExit()
{
	std::cout << "EXIT" <<std::endl;
	std::exit;
}

//ADD, SEARCH, EXIT, それ以外の処理にそれぞれ飛ぶ
void	handleCommand(const std::string cmd, PhoneBook& p)
{
	if (cmd == "ADD")
		executeAdd(p);
	else if (cmd == "SEARCH")
		executeSearch(p);
	else if (cmd == "EXIT")
		executeExit();
}

int	main()
{
	PhoneBook	p;

	while (true)
	{
		//todo: 標準入力を何でやる？
		std::string	cmd;
		std::cin >> cmd;
		handleCommand(cmd, p);
	}
	return (0);
}
