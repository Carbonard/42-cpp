#include "Point.hpp"

Point::Point()
: x(0), y(0)
{
	return;
}

Point::Point(Point &other)
: x(other.x), y(other.y)
{
	return;
}

Point::Point(const Fixed &x, const Fixed &y)
: x(x), y(y)
{
	return;
}

Point &Point::operator =(Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
	return;
}

const Fixed &Point::getX(void) const
{
	return (this->x);
}

const Fixed &Point::getY(void) const
{
	return (this->y);
}
