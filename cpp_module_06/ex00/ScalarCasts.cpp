#include "Scalar.hpp"
#include <limits>
#include <cmath>

static bool	charCastable(int nb)
{
	return !(nb > std::numeric_limits<char>::max()
		|| nb < std::numeric_limits<char>::min());
}

static bool	charCastable(float nb)
{
	return !(nb > std::numeric_limits<char>::max()
		|| nb < std::numeric_limits<char>::min()
		|| nb != nb);
}

static bool	charCastable(double nb)
{
	return !(nb > std::numeric_limits<char>::max()
		|| nb < std::numeric_limits<char>::min()
		|| nb != nb);
}

Scalar	Scalar::toChar() const
{
	Scalar ret;

	if (this->_type == UNDEFINED)
		return ret;

	switch (this->_type)
	{
	case CHAR:
		ret._value.c = this->_value.c;
		break;
	case INT:
		if (!charCastable(this->_value.i))
			return ret;
		ret._value.c = static_cast<char>(this->_value.i);
		break;
	case FLOAT:
		if (!charCastable(this->_value.f))
			return ret;
		ret._value.c = static_cast<char>(this->_value.f);
		break;
	case DOUBLE:
		if (!charCastable(this->_value.d))
			return ret;
		ret._value.c = static_cast<char>(this->_value.d);
		break;
	
	default:
		break;
	}

	ret._type = CHAR;

	return ret;
}

static bool	intCastable(float nb)
{
	return !(nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min()
		|| nb != nb);
}

static bool	intCastable(double nb)
{
	return !(nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min()
		|| nb != nb);
}

Scalar	Scalar::toInt() const
{
	Scalar ret;

	if (this->_type == UNDEFINED)
		return ret;

	switch (this->_type)
	{
	case CHAR:
		ret._value.i = static_cast<int>(this->_value.c);
		break;
	case INT:
		ret._value.i = this->_value.i;
		break;
	case FLOAT:
		if (!intCastable(this->_value.f))
			return ret;
		ret._value.i = static_cast<int>(this->_value.f);
		break;
	case DOUBLE:
		if (!intCastable(this->_value.d))
			return ret;
		ret._value.i = static_cast<int>(this->_value.d);
		break;
	
	default:
		break;
	}

	ret._type = INT;

	return ret;
}

static bool	floatCastable(double nb)
{
	if (nb == std::numeric_limits<double>::infinity()
	|| nb == -std::numeric_limits<double>::infinity()
	|| nb != nb /* nb == nan */)
		return true;
	if (static_cast<float>(nb) == std::numeric_limits<float>::infinity()
	|| static_cast<float>(nb) == -std::numeric_limits<float>::infinity())
		return false;
	return true;
}

Scalar	Scalar::toFloat() const
{
	Scalar ret;

	if (this->_type == UNDEFINED)
		return ret;

	switch (this->_type)
	{
	case CHAR:
		ret._value.f = static_cast<float>(this->_value.c);
		break;
	case INT:
		ret._value.f = static_cast<float>(this->_value.i);
		break;
	case FLOAT:
		ret._value.f = this->_value.f;
		break;
	case DOUBLE:
		if (!floatCastable(this->_value.d))
			return ret;
		ret._value.f = static_cast<float>(this->_value.d);
		break;
	
	default:
		break;
	}

	ret._type = FLOAT;

	return ret;
}

Scalar	Scalar::toDouble() const
{
	Scalar ret;

	if (this->_type == UNDEFINED)
		return ret;

	switch (this->_type)
	{
	case CHAR:
		ret._value.d = static_cast<double>(this->_value.c);
		break;
	case INT:
		ret._value.d = static_cast<double>(this->_value.i);
		break;
	case FLOAT:
		ret._value.d = static_cast<double>(this->_value.f);
		break;
	case DOUBLE:
		ret._value.d = this->_value.d;
		break;
	
	default:
		break;
	}

	ret._type = DOUBLE;

	return ret;
}
