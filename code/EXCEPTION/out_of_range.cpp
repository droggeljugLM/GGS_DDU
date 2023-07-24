
#include <iostream>
#include <vector>

int main()
{
	try
	{
		std::vector<int> int_vec{ 1,2,3,4,5 };
		int_vec.at(10);
	}
	catch (const std::out_of_range& except)
	{
		std::cout << "EXCEPTION : " << except.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "EXCEPTION : unknown exception" << std::endl;
	}
	return 0;
}

namespace how_to_avoid_error
{

template<typename T>
class vector_t
{
public:
	T& operator[](int index) const;
private:
	std::vector<T> data;
};

template<typename T>
T& vector_t<T>::operator[](int i) const
{
	if (i >= data.size())
	{
		throw std::out_of_range("Test.data is out of range");
	}
	return data[i];
}

}