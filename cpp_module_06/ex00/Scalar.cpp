#include "Scalar.hpp"
#include "isLiteral.hpp"
#include <cstdlib>

Scalar::Scalar(): _type(UNDEFINED)
{
}

Scalar::Scalar(const Scalar &other)
{
	*this = other;
}

Scalar &Scalar::operator=(const Scalar &other)
{
	this->_type = other._type;
	this->_value = other._value;
	return *this;
}

Scalar::~Scalar()
{
}

bool	Scalar::isValid() const
{
	return this->_type != UNDEFINED;
}

void	Scalar::setChar(char c)
{
	this->_type = CHAR;
	this->_value.c = c;
}

void	Scalar::setInt(int i)
{
	this->_type = INT;
	this->_value.i = i;
}

void	Scalar::setFloat(float f)
{
	this->_type = FLOAT;
	this->_value.f = f;
}

void	Scalar::setDouble(double d)
{
	this->_type = DOUBLE;
	this->_value.d = d;
}

void	Scalar::setLiteral(const std::string &literal)
{
	static const 	std::string types[] = {
		[CHAR] = std::string("char"),
		[INT] = std::string("int"),
		[FLOAT] = std::string("float"),
		[DOUBLE] = std::string("double"),
		[UNDEFINED] = std::string("undefined")
	};

	if (isLiteralInt(literal))
		this->setInt(std::atoi(literal.c_str()));
	else if (isLiteralChar(literal))
		this->setChar(getChar(literal));
	else if (isLiteralFloat(literal))
		this->setFloat(static_cast<float>(std::atof(literal.c_str())));
	else if (isLiteralDouble(literal))
		this->setDouble(std::atof(literal.c_str()));
	else
		this->_type = UNDEFINED;

	std::cout << "\e[34m" << "Type: " << types[this->_type] << std::endl << "\e[0m";
}
