
#include <thread>
#include <iostream>

void testFunction()
{
	std::cout << "child thread: testFunction" << std::endl;
}

class TestClass
{
public:
	void operator()()
	{
		std::cout << "child thread: testClass" << std::endl;
	}

	void testClassFunction()
	{
		std::cout << "child thread: testClassFunctiuon" << std::endl;
	}
};

int main()
{
	TestClass testClass;
	{
		std::thread testThread1(testFunction);
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
		std::thread testThread2(testClass);
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
		std::thread testThread3(&TestClass::testClassFunction, &testClass);
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
		std::thread testThread4([]() {std::cout << "child thread: lambda" << std::endl; });
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
	std::cout << std::endl;

	std::cout << "main thread " << std::endl;
	return 0;
}