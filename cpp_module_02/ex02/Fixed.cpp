#include "Fixed.hpp"
#include <iostream>

#define NDEBUG

void print_debug(std::string message)
{
	#ifdef DEBUG
		std::cout << message << std::endl;
	#else
		(void)message;
	#endif
}


// CONSTRUCTORS / DESTRUCTOR

Fixed::Fixed( void )
{
	print_debug("Default constructor called");
	_value = 0;
}

Fixed::Fixed( const int n )
{
	print_debug("Int constructor called");
	_value = (n << _fbits);
}

Fixed::Fixed( const float f )
{
	print_debug("Float constructor called");
	_value = (int)( f * (float)(1 << _fbits) + 0.5f );
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


// OPERATORS

Fixed &Fixed::operator =( const Fixed &other )
{
	print_debug("Copy assignment operator called");
	_value = other.getRawBits();
	return (*this);
}


// COMPARING OPERATORS

bool Fixed::operator >( const Fixed &other ) const
{
	return (this->_value > other._value);
}

bool Fixed::operator <( const Fixed &other ) const
{
	return (this->_value < other._value);
}

bool Fixed::operator >=( const Fixed &other ) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator <=( const Fixed &other ) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator ==( const Fixed &other ) const
{
	return (this->_value == other._value);
}

bool Fixed::operator !=( const Fixed &other ) const
{
	return (this->_value != other._value);
}


// ARITHMETIC OPERATORS

Fixed Fixed::operator +( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return(result);
}

Fixed Fixed::operator -( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return(result);
}

Fixed Fixed::operator *( const Fixed &other ) const
{
	Fixed result;
	int newRawBits = (int)( ( this->_value * other._value ) >> _fbits );
	result.setRawBits(newRawBits);
	return(result);
}

Fixed Fixed::operator /( const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(( ((long)this->_value) << _fbits ) / other._value);
	return(result);
}


// OTHER OPERATORS

Fixed &Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed &Fixed::operator--( void )
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}


// SET / GET

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}


// CONVERSIONS

float Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _fbits));
}

int Fixed::toInt( void ) const
{
	return (_value >> _fbits);
}


// MAX / MIN

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}
