#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	int n = std::rand();

	switch (n % 3)
	{
	case 0:
		std::cout << "\e[34mRandomly generated: A\e[0m" << std::endl;
		return new A;
		break;

	case 1:
		std::cout << "\e[34mRandomly generated: B\e[0m" << std::endl;
		return new B;
		break;

	case 2:
		std::cout << "\e[34mRandomly generated: C\e[0m" << std::endl;
		return new C;
		break;
	
	default:
		return NULL;
		break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's C" << std::endl;
	else
		std::cout << "It's a Base" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "It's A" << std::endl;
	}
	catch(...)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "It's B" << std::endl;
		}
		catch(...)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "It's C" << std::endl;
			}
			catch(...)
			{
				std::cout << "It's a Base" << std::endl;
			}
		}
	}
}

int main()
{
	std::srand(std::time(NULL));
	A a;
	B b;
	C c;

	std::cout << "Identifying references:" << std::endl;
	identify(a);
	identify(b);
	identify(c);

	std::cout << "Identifying pointers:" << std::endl;
	identify(&a);
	identify(&b);
	identify(&c);

	for (int i = 0; i < 5; i++)
	{
		Base *randPtr = generate();
		// std::cout << "Random generated:" << std::endl;
		identify(randPtr);
		delete randPtr;
	}

	return 0;
}