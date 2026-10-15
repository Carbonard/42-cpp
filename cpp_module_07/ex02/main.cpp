#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main()
{
{
	std::cout << "---------- SUBJECT TESTS ----------" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}
{
	std::cout << "---------- MY TESTS ----------" << std::endl;
	// int *n = new int();
	// std::cout << *n << std::endl;

	Array<int> arr0;

	Array<int> arr(5);
	arr[1] = 42;
	for (size_t i = 0; i < arr.size() + 1; i++)
	{
		try
		{
			int a = arr[i];
			std::cout << "arr[" << i << "] = " << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	Array<int> arr2(arr);
	arr0 = arr2;
	arr0 = arr;
	arr[1] = 24;
	arr2[1] = -42;
	std::cout << std::endl;
	for (size_t i = 0; i < arr.size() + 1; i++)
	{
		try
		{
			int a = arr[i];
			std::cout << "arr[" << i << "] = " << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < arr2.size() + 1; i++)
	{
		try
		{
			int a = arr2[i];
			std::cout << "arr2[" << i << "] = " << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	for (size_t i = 0; i < arr0.size() + 1; i++)
	{
		try
		{
			int a = arr0[i];
			std::cout << "arr0[" << i << "] = " << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}}

}