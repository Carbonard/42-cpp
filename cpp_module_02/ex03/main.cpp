#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
{
	Point a(Fixed(-1), Fixed(0));
	Point b(Fixed(1), Fixed(1));
	Point c(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
{
	Point a(Fixed(-1), Fixed(0));
	Point c(Fixed(1), Fixed(1));
	Point b(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
{
	Point b(Fixed(-1), Fixed(0));
	Point a(Fixed(1), Fixed(1));
	Point c(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
{
	Point b(Fixed(-1), Fixed(0));
	Point c(Fixed(1), Fixed(1));
	Point a(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
{
	Point c(Fixed(-1), Fixed(0));
	Point a(Fixed(1), Fixed(1));
	Point b(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
{
	Point c(Fixed(-1), Fixed(0));
	Point b(Fixed(1), Fixed(1));
	Point a(Fixed(2), Fixed(-1));
	Point p(Fixed(0), Fixed(0));
	if (bsp(a, b, c, p))
		std::cout << "It's inside! :D" << std::endl;
	else
		std::cout << "It's outside! D:" << std::endl;
}
	return 0;
}
