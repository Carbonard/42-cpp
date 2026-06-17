#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:

	int	_value;
	static const int _fbits = 8;

public:

	Fixed( void );
	Fixed( const int n );
	Fixed( const float f );
	Fixed( const Fixed &other );

	~Fixed( void );

	Fixed &operator =( const Fixed &other );

	bool operator >( const Fixed &other ) const;
	bool operator <( const Fixed &other ) const;
	bool operator >=( const Fixed &other ) const;
	bool operator <=( const Fixed &other ) const;
	bool operator ==( const Fixed &other ) const;
	bool operator !=( const Fixed &other ) const;

	Fixed operator +( const Fixed &other ) const;
	Fixed operator -( const Fixed &other ) const;
	Fixed operator *( const Fixed &other ) const;
	Fixed operator /( const Fixed &other ) const;

	Fixed &operator ++( void );
	Fixed operator ++( int );
	Fixed &operator --( void );
	Fixed operator --( int );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
