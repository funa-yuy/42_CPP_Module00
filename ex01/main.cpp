#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	p;

	while (true)
	{
		//todo: 標準入力を何でやる？
		std::cout << "----- Enter the ADD, SEARCH, or EXIT command. -----" <<std::endl;
		std::string	cmd;
		while (cmd.empty()) {
			std::getline(std::cin, cmd);
		}
		if (cmd == "ADD")
			p.executeAdd();
		else if (cmd == "SEARCH")
			p.executeSearch();
		else if (cmd == "EXIT")
			p.executeExit();
	}

	return (EXIT_SUCCESS);
}
