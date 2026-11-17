#include "iter.hpp"
#include "testFunctions.hpp"
#include <string>
#include <string.h>
#include <iostream>

void toUpper(char &c)
{
	if (std::islower(c))
		c += 'A' - 'a';
	else if (std::isupper(c))
		c += 'a' - 'A';
}

void doubleNbr(int &n)
{
	n *= 2;
}

int main()
{

//	Test array of char
{
	char str[] = "abcde";
	size_t N = strlen(str);

	std::cout << "Original array: " << str << std::endl;
	
	iter(str, N, toUpper);
	
	std::cout << "Modified (toUpper): " << str << std::endl;
	
	iter(str, N, addOne<char>);
	
	std::cout << "Modified (addOne): " << str << std::endl;

	resetMean();
	iter(str, N, addMean<char>);
	std::cout << "The mean is " << static_cast<char>(getMean()) << std::endl;
}
//	Test array of int
{
	int arr[] = {0, 1, 2, 3, 4, 5};
	size_t N = sizeof(arr) / sizeof(int);

	std::cout << "Original array: " << "{";
	for (size_t i = 0; i < N; i++)
	{
		std::cout << " " << arr[i] << " ";
	}
	std::cout << "}" << std::endl;

	iter(arr, N, doubleNbr);

	std::cout << "Modified (doubleNbr): " << "{";
	for (size_t i = 0; i < N; i++)
	{
		std::cout << " " << arr[i] << " ";
	}
	std::cout << "}" << std::endl;

	iter(arr, N, addOne<int>);

	std::cout << "Modified (addOne): " << "{";
	for (size_t i = 0; i < N; i++)
	{
		std::cout << " " << arr[i] << " ";
	}
	std::cout << "}" << std::endl;

	resetMean();
	iter(arr, N, addMean<int>);
	std::cout << "The mean is " << getMean() << std::endl;
}
	return 0;
}
