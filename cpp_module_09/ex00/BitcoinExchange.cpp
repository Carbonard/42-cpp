#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <sstream>

void readCSV(std::string csvFileName, t_map& map)
{
	std::ifstream csvFile(csvFileName.c_str());
	if (!csvFile)
		throw std::runtime_error("Error: data file could not be opened");
	char c;
	std::string aux, key;
	getline(csvFile, aux);
	aux = "";
	while (csvFile.get(c))
	{
		if (c == ',')
		{
			key = aux;
			aux = "";
		}
		else if (c == '\n')
		{
			std::stringstream ss(aux);
			ss >> map[key];
			aux = "";
		}
		else
			aux += c;
	}
}

static int getYear(const std::string& line, size_t& i)
{
	while (i < line.size() && std::isdigit(line[i]))
		i++;
	if (i == 0 || i > 8)
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	return std::atoi(line.c_str());
}

static int getDateNumber(const std::string &line, size_t& i)
{
	if (line[i] != '-' || !std::isdigit(line[i+1]))
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	i++;
	int ret = std::atoi(line.substr(i).c_str());
	size_t aux = i;
	while (i < aux+2 && std::isdigit(line[i]))
		i++;

	return ret;
}

static void checkSeparator(const std::string& line, size_t& i)
{
	while (line[i] == ' ')
		i++;
	if (line[i] != '|')
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	i++;
	while (line[i] == ' ')
		i++;
}

static double getValue(const std::string& line, size_t& i)
{
	double value;
	if (i == line.size())
		throw std::runtime_error(std::string("Error: bad input => ") + line);
	std::stringstream ss(line.substr(i));
	ss >> value;
	return value;
}

static bool checkDate(const std::string& strDate, int year, int month, int day)
{
	if (year < 1000 || year > 9999)
		throw std::runtime_error(std::string("Error: bad year => ") + strDate);
	if (month <= 0 || month > 12)
		throw std::runtime_error(std::string("Error: bad month => ") + strDate);
	if (month <= 0 || day > 31)
		throw std::runtime_error(std::string("Error: bad day => ") + strDate);
	if (day == 31
		&& (month == 4 || month == 6 || month == 9 || month == 11))
		throw std::runtime_error(std::string("Error: bad day => ") + strDate);
	if (month == 2)
	{
		if (day > 29)
			throw std::runtime_error(std::string("Error: bad day => ") + strDate);
		if (month == 2 && day == 29 && !(year%4 == 0 && (year%100 != 0 || year%400 == 0)))
			throw std::runtime_error(std::string("Error: bad day => ") + strDate);
	}
	return true;
}

static bool checkValue(std::string strVal, double value)
{
	if (value < 0)
		throw std::runtime_error(std::string("Error: not a positive number."));
	if (value > 1000)
		throw std::runtime_error(std::string("Error: too large a number."));
	size_t i = 0;
	while (std::isdigit(strVal[i]))
		i++;
	if (strVal[i] == '.')
		i++;
	while (std::isdigit(strVal[i]))
		i++;
	while (strVal[i] == ' ')
		i++;
	return (i != strVal.length());
}

static void parseLine(const std::string& line, std::string& date, double& value)
{
	size_t i = 0;
	int day, month, year;

	year = getYear(line, i);
	month = getDateNumber(line, i);
	day = getDateNumber(line, i);
	date = line.substr(0, i);
	checkSeparator(line, i);
	value = getValue(line, i);
	checkDate(date, year, month, day);
	if (checkValue(line.substr(i), value))
		throw std::runtime_error(std::string("Error: bad input => ") + line);
}

static double getClosestPrice(t_map map, const std::string &key)
{
	t_map::iterator it = map.begin();
	t_map::iterator it_next = map.begin();
	if (it_next != map.end())
		it_next++;
	else
		throw std::runtime_error("Error: data not found");
	while (it_next != map.end())
	{
		if (it_next->first > key)
			return it->second;
		it++;
		it_next++;
	}
	return it->second;
}

void printValues(t_map prices, char* inputFileName)
{
	std::ifstream file(inputFileName);
	if (!file)
		throw std::runtime_error("Error: input file could not be opened");
	std::string line;
	std::string date;
	double value;
	double price;
	std::getline(file, line);
	while (!file.eof())
	{
		getline(file, line);
		try
		{	
			parseLine(line, date, value);
			price = getClosestPrice(prices, date);
			std::cout << date << " => " << value << " = " << value * price << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
}