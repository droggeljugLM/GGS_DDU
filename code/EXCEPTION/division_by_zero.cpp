
#include <iostream>

double divide(double dividend, double divisor)
{
	if (!divisor)
	{
		throw("divisor is zero");
	}
	return dividend / divisor;
}

void inputNum(const std::string& str, double& num)
{
	std::cout << str << std::endl;
	while (std::cin >> num, !std::cin.eof())
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
}

int main()
{
	double dividend = 0;
	double divisor = 0;
	inputNum("please input dividend: ", dividend);
	inputNum("please input divisor: ", divisor);
	try
	{
		std::cout << divide(dividend, divisor) << std::endl;
	}
	catch (const char* except)
	{
		std::cout << "EXCEPTION : " << except << std::endl;
	}
	return 0;
}