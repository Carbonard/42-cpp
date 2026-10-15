#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

{
	int e = a;
	int &f = min(a,e);
	if (&f == &e && &f != &a)
		std::cout << "In case of equallity, the second one was returned" << std::endl;
}
{
	std::string e = c;
	std::string &f = min(c,e);
	if (&f == &e && &f != &c)
		std::cout << "In case of equallity, the second one was returned" << std::endl;
}
	return 0;
}