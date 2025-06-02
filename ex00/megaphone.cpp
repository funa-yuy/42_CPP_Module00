#include<iostream>
#include<string>

std::string StrToUpper(const std::string& str)
{
	std::string result;

	result = str;
	for (size_t i = 0; i < result.size(); i++)
		result[i] = std::toupper(result[i]);
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << StrToUpper(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}
