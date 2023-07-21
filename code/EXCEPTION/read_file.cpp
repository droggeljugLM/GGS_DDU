
#include <iostream>
#include <fstream>

void outputContent(const std::string& filename)
{
	std::ifstream ifs(filename);
	std::string line;
	if (ifs.is_open())
	{
		while (ifs >> line)
		{
			std::cout << line << std::endl;
		}
		if (ifs.bad())
		{
			throw std::runtime_error("ifs is corrupted");
		}
		ifs.close();
	}
	else
	{
		throw std::string("no file exist");
	}
}

int main()
{
	std::string str;

	while (std::cin >> str, !std::cin.eof())
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
		break;
	}

	try
	{
		outputContent(str);
	}
	catch (const std::string& except)
	{
		std::cout << "EXCEPTION : " << except << std::endl;
	}
	catch (...)
	{
		std::cout << "EXCEPTION : unknown exception" << std::endl;
	}
	return 0;
}