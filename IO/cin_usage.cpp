
#include <iostream>

int main()
{
	int i = 0;
	std::cout << "please input i" << std::endl;
	while (std::cin >> i, !std::cin.eof())
	{
		if (std::cin.bad())
		{
			throw std::runtime_error("cin is corrupted");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "format error, please try again" << std::endl;
			continue;
		}
		std::cout << i << std::endl;
	}
	return 0;
}

int do_not_use_cin_like_this()
{
	int i = 10;
	std::cout << "please input i" << std::endl;
	std::cin >> i;
	std::cout << i << std::endl;
	return 0;
}
