#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

int main()
{
{
	int a[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
	std::vector<int> v(a, a + (sizeof(a)/sizeof(int)));
	{
		Span s(100);
		s.addNumbers(v);
		s.print();
		std::cout
			<< "longest span: " << std::endl << s.longestSpan()
			<< std::endl
			<< "shortest span: " << std::endl << s.shortestSpan()
			<< std::endl;
	}
	{
		Span s(100);
		s.addRange(v.begin() + 2, v.end() - 1);
		s.print();
		std::cout
			<< "longest span: " << std::endl << s.longestSpan()
			<< std::endl
			<< "shortest span: " << std::endl << s.shortestSpan()
			<< std::endl;
	}
}
{
	int N = 8192;
	for (int i = 0; i < 5; i++)
	{
		N *= 2;
		std::cout << std::endl << "Test with N = " << N << std::endl;
		Span s(N);
		try
		{
			int n;
			for (int i = 0; i < N + 1; i++)
			{
				n = std::rand();
				s.addNumber(n);
				// std::cout << "added " << n << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout
			<< "longest span: " << std::endl << s.longestSpan()
			<< std::endl
			<< "shortest span: " << std::endl << s.shortestSpan()
			<< std::endl;
	}
}
	return 0;
}