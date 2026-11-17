#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
	std::cout
		<< ">>>>>>>>>> SUBJECT TEST <<<<<<<<<<"
		<< std::endl << std::endl;
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
	std::cout << std::endl
		<< ">>>>>>>>>> MY OWN TESTS <<<<<<<<<<"
		<< std::endl << std::endl;
{
	int a[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
	std::vector<int> v(a, a + (sizeof(a)/sizeof(int)));
	{
		Span s(100);
		s.addNumbers(v);
		std::cout << "Span: ";
		s.print();
		std::cout
			<< "longest span: " << s.longestSpan()
			<< std::endl
			<< "shortest span: " << s.shortestSpan()
			<< std::endl
			<< std::endl;
	}
	{
		Span s(100);
		s.addRange(v.begin() + 2, v.end() - 1);
		std::cout << "Span: ";
		s.print();
		std::cout
			<< "longest span: " << s.longestSpan()
			<< std::endl
			<< "shortest span: " << s.shortestSpan()
			<< std::endl;
	}
}
{
	int N = 64;
	for (int i = 0; i < 13; i++)
	{
		N *= 2;
		std::cout << "-------------------------" << std::endl << "Test with N = " << N << std::endl << std::endl;
		Span s(N);
		int n;
		for (int i = 0; i < N + 1; i++)
		{
			try
			{
				n = std::rand();
				s.addNumber(n);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		std::cout << std::endl
			<< "longest span: " << s.longestSpan()
			<< std::endl << std::endl
			<< "shortest span: " << s.shortestSpan()
			<< std::endl;
	}
}
	return 0;
}