#include "brackets.hpp"

std::string&	brackets(std::string& str)
{
	int ascii_set[256] = { EMPTY };
	int ascii_char;

	for (size_t i = 0; i < str.length(); i++)
	{
		ascii_char = std::tolower(static_cast<int>(str[i]));
		if (ascii_set[ascii_char] == EMPTY)
			ascii_set[ascii_char] = UNIQUE;
		else
			ascii_set[ascii_char] = REPEATED;
	}

	for (size_t i = 0; i < str.length(); i++)
	{
		ascii_char = std::tolower(static_cast<int>(str[i]));
		if (ascii_set[ascii_char] == UNIQUE)
			str[i] = '(';
		else
			str[i] = ')';
	}
	
	return str;
}

int	main(int argc, char** argv)
{	
	if (argc != 2)
		std::cerr << "Wrong number of arguments!" << std::endl;
	else
	{
		std::string src = argv[1];
		std::cout << brackets(src) << std::endl;
	}

	return 0;
}
