#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNDEFINED
};

union u_scalar
{
	char c;
	int i;
	float f;
	double d;
};

class Scalar
{
private:
	e_type		_type;
	u_scalar	_value;

public:
	Scalar();
	Scalar(const Scalar &other);
	Scalar &operator=(const Scalar &other);
	~Scalar();

	void	setChar(char c);
	void	setInt(int i);
	void	setFloat(float f);
	void	setDouble(double d);
	void	setLiteral(const std::string &str);

	Scalar	toChar() const;
	Scalar	toInt() const;
	Scalar	toFloat() const;
	Scalar	toDouble() const;

	void	print(std::ostream &os) const;

	bool	isValid() const;
};

std::ostream &operator <<(std::ostream &os, const Scalar &scalar);

#endif
