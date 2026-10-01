#include "Scalar.hpp"
#include <iostream>
#include <cmath>

#define MIN_EXP_PRINTABLE 6

void Scalar::print(std::ostream &os) const
{
	switch (this->_type)
	{
	case CHAR:
		if (this->_value.c > 32 && this->_value.c < 127)
			os << this->_value.c;
		else
			os << "Non displayable";
		break;
	case INT:
		os << this->_value.i;
		break;
	case FLOAT:
		os << this->_value.f;
		if (this->_value.f == std::floor(this->_value.f)
		&& std::floor(std::log10(std::abs(this->_value.f))) < MIN_EXP_PRINTABLE)
			os << ".0";
		os << "f";
		break;
	case DOUBLE:
		os << this->_value.d;
		if (this->_value.d == std::floor(this->_value.d)
		&& std::floor(std::log10(std::abs(this->_value.d))) < MIN_EXP_PRINTABLE)
			os << ".0";
		break;
	
	default:
		os << "impossible";
		break;
	}
}

std::ostream	&operator <<(std::ostream &os, const Scalar &scalar)
{
	scalar.print(os);
	return os;
}