#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(Point &other);
	Point(const Fixed &x, const Fixed &y);
	Point &operator =(Point &other);
	~Point();

	const Fixed &getX() const;
	const Fixed &getY() const;
};

#endif
