
#include <iostream>
#include <sstream>

int main()
{
	std::string str("123"); // try str("abc")
	std::istringstream iss(str);

	int i = 0;
	iss >> i;
	if (iss.bad())
	{
		throw std::runtime_error("iss is corrupted");
	}
	if (iss.fail())
	{
		iss.clear();
		iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "string format error" << std::endl;
	}
	else
	{
		std::cout << i << std::endl;
	}
	return 0;
}