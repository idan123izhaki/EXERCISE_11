#include <iostream>
#include <vector>
#include <thread>


void printing_prime_numbers(int, int);
void task_1();
void printing_perfect_numbers(int, int);
void task_2();

int main()
{
	std::cout << "Task_1:" << std::endl;
	task_1();
	system("PAUSE");
	std::cout << "Task_2:" << std::endl;
	task_2();
	system("PAUSE");
	return 0;
}



void task_1()
{
	std::vector<std::thread> threads;
	int number;
	std::cout << "Please enter an integer number: ";
	std::cin >> number;
	for (; number >= 2; number -= 20)
	{
		if (number > 20)
			threads.emplace_back(printing_prime_numbers, number - 19, number);
		else
			threads.emplace_back(printing_prime_numbers, 2, number);
	}
	for (std::thread& t : threads)
		t.join();
}


void printing_prime_numbers(int a, int b)
{
	bool flag;
	int check, count = 0;
	for (int i = a; i <= b; ++i)
	{
		flag = true;
		check = 2;
		while (flag && (check * check <= i))
		{
			if (i % check == 0)
				flag = false;
			check += 1;
		}
		if (flag == true)
		{
			std::cout << i << std::endl;
			++count;
		}
	}
}


void task_2()
{
	std::vector<std::thread> threads;
	long int number;
	std::cout << "Please enter an integer number greater then 1,000,000: ";
	std::cin >> number;
	for (; number >= 6; number -= 1000)
	{
		if (number > 1000)
			threads.emplace_back(printing_perfect_numbers, number - 999, number);
		else
			threads.emplace_back(printing_perfect_numbers, 6, number);
	}
	for (std::thread& t : threads)
		t.join();
}


void printing_perfect_numbers(int a, int b)
{
	int counter, sum;
	for (int i = a; i <= b; ++i)
	{
		counter = 1; sum = 0;
		while (counter <= i / 2)
		{
			if (i % counter == 0)
				sum += counter;
			++counter;
		}
		if (sum == i) std::cout << i << std::endl;
	}
}