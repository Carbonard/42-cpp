#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main( void ) {
{
	std::cout << "[ SUBJECT TESTS ]" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}
{
	std::cout << "[ CUSTOM TESTS ]" << std::endl;
	int integers[] = {0, 1, 2, 3, 4, 5, 10, -1, -2, -3, -10, 42};
	float rationals[] = {0, 1, -1, 10, -10, 0.5, 1.5, (float)1/3, -0.5, -1.5, (float)-1/3, 42};
	
	for (int i = 0; integers[i] != 42; i++)
		for (int j = 0; rationals[j] != 42; j++)
			std::cout
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << ">" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] > rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "<" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] < rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << ">=" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] >= rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "<=" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] <= rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "==" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] == rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "!=" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(3) << std::setprecision(2) <<  (integers[i] != rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "+" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(5) << std::setprecision(2) <<  (integers[i] + rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "-" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(5) << std::setprecision(2) <<  (integers[i] - rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "*" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(5) << std::setprecision(2) <<  (integers[i] * rationals[j]) << " | "
				<< std::setw(3) << std::left << std::setprecision(2) << integers[i] << "/" << std::setw(5) << std::setprecision(2) << rationals[j] << " " << std::setw(5) << std::setprecision(2) <<  (integers[i] / rationals[j]) << " | "
				<< "max" << integers[i] << rationals[j] << " " << Fixed::max(integers[i], rationals[j]) << " | "
				<< "min" << integers[i] << rationals[j] << " " << Fixed::min(integers[i], rationals[j]) << " | "
				<< std::endl;
	
	Fixed a(__INT_MAX__ / 3 * 2);
	Fixed b = a + a;
	std::cout << a << std::endl << b << std::endl;
}	
	return 0;
}
