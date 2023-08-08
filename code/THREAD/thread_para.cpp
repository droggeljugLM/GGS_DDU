
#include <thread>
#include <iostream>

class TestClass
{
public:
	TestClass(int i_) :i(i_) { std::cout << "TestClass()" << std::endl; };
	TestClass(const TestClass& testClass_) :i(testClass_.i) { std::cout << "TestClass(const TestClass&)" << std::endl; }
	~TestClass() { std::cout << "~TestClass()" << std::endl; }
	int i;
};

void testFunction1(TestClass testClass_)
{
	std::cout << "i = " << testClass_.i << std::endl;
}

void testFunction2(const TestClass& testClass_)
{
	std::cout << "i = " << testClass_.i << std::endl;
}

int main()
{
	{
		std::thread testThread1(testFunction1, 20);
		if (testThread1.joinable())
		{
			testThread1.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}
	}
	std::cout << std::endl;
	{
		std::thread testThread2(testFunction2, 20);
		if (testThread2.joinable())
		{
			testThread2.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}
	}
	std::cout << std::endl;
	{
		std::thread testThread3(testFunction1, TestClass(20));
		if (testThread3.joinable())
		{
			testThread3.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}
	}
	std::cout << std::endl;
	{
		std::thread testThread4(testFunction2, TestClass(20));
		if (testThread4.joinable())
		{
			testThread4.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}
	}
	return 0;
}