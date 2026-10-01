#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>

bool	isLiteralInt(const std::string &str)
{
	if (str.length() > 11 || str.length() == 0)
		return false;

	size_t i = 0;
	if ((str[0] == '-' || str[0] == '+') && str.length() > 1)
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}

	long number = std::atol(str.c_str());
	if (number > std::numeric_limits<int>::max()
	|| number < std::numeric_limits<int>::min())
		return false;

	return true;
}

bool	isLiteralChar(const std::string &str)
{
	if (str == "'\\''")
		return true;
	if (str.length() != 3)
		return false;
	if (str[0] != '\'' || str[2] != '\'')
		return false;
	return true;
}

char	getChar(const std::string &str)
{
	if (!isLiteralChar(str))
		return 0;
	if (str == "'\\''")
		return '\'';
	return (str[1]);
}

bool	isLiteralFloat(const std::string &str)
{
	if (str.length() == 0 || str == "." || str == "f" || str == ".f")
		return false;

	size_t i = 0;
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	if (str.substr(i) == "inff" || str.substr(i) == "nanf")
		return true;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f' && str.length() == i + 1)
		return true;

	return false;
}

bool	isLiteralDouble(const std::string &str)
{
	if (str.length() == 0 || str == ".")
		return false;

	size_t i = 0;
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	if (str.substr(i) == "inf" || str.substr(i) == "nan")
		return true;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.length() == i)
		return true;

	return false;
}
