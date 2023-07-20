
#include <iostream>
#include <sstream>

int main()
{
	int i = 123; // try double i = 1.23
	std::ostringstream oss;
	oss << i << std::endl;
	if (oss.bad())
	{
		throw std::runtime_error("oss is corrupted");
	}
	std::cout << oss.str() << std::endl;
	return 0;
}