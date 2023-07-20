
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fileName;
	std::string fileContent;

	while (std::cin >> fileName, !std::cin.eof())
	{
		if (std::cin.bad())
		{
			throw std::runtime_error("cin is corrupted");
		}

		std::ifstream ifs(fileName);
		if (ifs.is_open())
		{
			while (std::getline(ifs, fileContent))
			{
				std::cout << fileContent << std::endl;
			}
			if (ifs.bad())
			{
				throw std::runtime_error("ifs is corrupted");
			}
			ifs.close();
		}
		else
		{
			ifs.clear();
			ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "no file exist, please try again" << std::endl;
			continue;
		}
	}
	return 0;
}