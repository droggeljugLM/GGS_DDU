
#include <thread>
#include <iostream>
#include <mutex>

class TestClass1
{
public:
	void addNum1(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			++num;
		}
	}

	void addNum2(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			++num;
		}
	}
	int num = 0;
};

class TestClass2
{
public:
	void addNum1(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			testMutex.lock();
			++num;
			testMutex.unlock();
		}
	}

	void addNum2(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			testMutex.lock();
			++num;
			testMutex.unlock();
		}
	}
	int num = 0;
	std::mutex testMutex;
};

int main()
{
	{
		TestClass1 testClass1;
		std::thread AddNum11(&TestClass1::addNum1, &testClass1, 1e7);
		std::thread AddNum12(&TestClass1::addNum2, &testClass1, 1e7);

		if (AddNum11.joinable())
		{
			AddNum11.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}

		if (AddNum12.joinable())
		{
			AddNum12.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}

		std::cout << testClass1.num << std::endl;
	}
	{
		TestClass2 testClass2;
		std::thread AddNum21(&TestClass2::addNum1, &testClass2, 1e7);
		std::thread AddNum22(&TestClass2::addNum2, &testClass2, 1e7);

		if (AddNum21.joinable())
		{
			AddNum21.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}

		if (AddNum22.joinable())
		{
			AddNum22.join();
		}
		else
		{
			std::cout << "create child thread error " << std::endl;
			return -1;
		}

		std::cout << testClass2.num << std::endl;
	}
	return 0;
}

class best_way_to_use_mutex
{
public:
	void addNum1(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			std::lock_guard<std::mutex> lg(testMutex);
			++num;
		}
	}

	void addNum2(unsigned count_)
	{
		for (size_t i = 0; i < count_; ++i)
		{
			std::lock_guard<std::mutex> lg(testMutex);
			++num;
		}
	}
	int num = 0;
	std::mutex testMutex;
};