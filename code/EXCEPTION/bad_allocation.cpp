
#include <iostream>
#include <memory>
#include <vector>

int main()
{
	try
	{
		while (1)
		{
			int* pi = new int[10e6];
		}
	}
	catch (const std::bad_alloc& except)
	{
		std::cout << "EXCEPTION : " << except.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "EXCEPTION : unknown exception" << std::endl;
	}
	return 0;
}

int another_example_for_mordern_cpp()
{
	try
	{
		std::vector<std::shared_ptr<int>> shared_int_vec;
		while (1)
		{
			std::shared_ptr<int> shared_int(new int[10e6]());
			shared_int_vec.push_back(shared_int);
		}
	}
	catch (const std::bad_alloc& except)
	{
		std::cout << "EXCEPTION : " << except.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "EXCEPTION : unknown exception" << std::endl;
	}
	return 0;

}