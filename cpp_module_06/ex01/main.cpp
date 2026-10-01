#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data d;
	d.number = 42;
	d.text = "Hello world";
	Data *ptr = Serializer::deserialize(Serializer::serialize(&d));
	if (&d == ptr)
		std::cout << "That's correct" << std::endl;
	else
		std::cout << "That's wrong" << std::endl;
	std::cout << std::endl << "Data info:" << std::endl << ptr->text << std::endl << ptr->number << std::endl;
}