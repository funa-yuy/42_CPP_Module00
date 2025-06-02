#include "PhoneBook.hpp"
#include "Contact.hpp"

void	executeAdd(PhoneBook& p)
{
	Contact	newContact;

	newContact = p.inputContact();
	p.addContact(newContact);
}

void	executeSearch(PhoneBook& p)
{
	p.displayContactList();
	size_t	index;
	std::cout << "index: ";
	std::cin >> index;
	p.displayContact(index);
}

void	executeExit()
{
	std::exit(EXIT_SUCCESS);
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
