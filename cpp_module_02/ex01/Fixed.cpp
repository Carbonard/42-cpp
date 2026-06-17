#include "Fixed.hpp"
#include <iostream>

#define DEBUG

void print_debug(std::string message)
{
	#ifdef DEBUG
		std::cout << message << std::endl;
	#else
		(void)message;
	#endif
}

Fixed::Fixed( void )
{
	print_debug("Default constructor called");
	_value = 0;
}

Fixed::Fixed( const int n )
{
	print_debug("Int constructor called");
	_value = n << _fbits;
}

Fixed::Fixed( const float f )
{
	print_debug("Float constructor called");
	_value = (int)( f * (float)(1 << _fbits) + 0.5f );
}

Fixed &Fixed::operator =( const Fixed &other )
{
	print_debug("Copy assignment operator called");
	_value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

Fixed::Fixed( const Fixed &other )
{
	print_debug("Copy constructor called");
	*this = other;
}

Fixed::~Fixed( void )
{
	print_debug("Destructor called");
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _fbits));
}

int Fixed::toInt( void ) const
{
	return (_value >> _fbits);
}

