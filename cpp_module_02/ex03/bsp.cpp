#include "Point.hpp"
#include <iostream>

Fixed slope(Point const &p, Point const &q)
{
	Fixed xIncrement(q.getX() - p.getX());
	Fixed yIncrement(q.getY() - p.getY());
	return (yIncrement / xIncrement);
}

bool sameLine(Point const &a, Point const &b, Point const &c)
{
	if (a.getX() == b.getX())
	{
		if (a.getX() == c.getX())
			return true;
		else
			return false;
	}
	else if (a.getX() == c.getX())
		return false;
	else if (slope(a, b) == slope(a, c))
		return true;
	else
		return false;
}

int spacePartition(
		Point const &partitionPoint1,
		Point const &partitionPoint2,
		Point const &p
		)
{
	Fixed v;
	if (partitionPoint1.getX() == partitionPoint2.getX())
	{
		v = p.getX() - partitionPoint1.getX();
	}
	else
	{
		Fixed m = slope(partitionPoint1, partitionPoint2);
		v = p.getY() - m * p.getX() - partitionPoint1.getY() + m * partitionPoint1.getX();
	}
	if (v > 0)
		return 1;
	if (v < 0)
		return -1;
	return 0;
}

bool sameSpacePartition(
		Point const &partitionPoint1,
		Point const &partitionPoint2,
		Point const &checkPoint1,
		Point const &checkPoint2
		)
{
	return (spacePartition(partitionPoint1, partitionPoint2, checkPoint1)
			== spacePartition(partitionPoint1, partitionPoint2, checkPoint2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (sameLine(a, b, c))
	{
		std::cerr << "The vertex are on the same line!" << std::endl;
		return false;
	}
	if (sameSpacePartition(a, b, c, point)
	&&	sameSpacePartition(b, c, a, point)
	&&	sameSpacePartition(c, a, b, point))
		return true;
	return false;
}