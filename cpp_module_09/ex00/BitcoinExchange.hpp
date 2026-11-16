#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>

typedef std::map<std::string, double> t_map;

void readCSV(std::string csvFileName, t_map& map);
void printValues(t_map prices, char* inputFileName);

#endif
