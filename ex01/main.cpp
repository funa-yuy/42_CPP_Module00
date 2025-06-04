#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	p;

	while (true)
	{
		std::cout << "----- Enter the ADD, SEARCH, or EXIT command. -----" <<std::endl;
		std::string	cmd;
		while (!std::getline(std::cin, cmd)) {
			std::exit(EXIT_SUCCESS);
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
