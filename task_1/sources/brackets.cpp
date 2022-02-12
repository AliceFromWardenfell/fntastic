#include "brackets.hpp"

std::string&	brackets(std::string& str)
{
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
