#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
	std::cout
		<< "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!"
		<< std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout
		<< "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!"
		<< std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout
		<< "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month."
		<< std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout
		<< "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

typedef void (Harl::*complainAction)(void);

typedef struct level_pair_s
{
	std::string str_level;
	complainAction action;	
}	level_pair_t;

void Harl::complain( std::string level )
{
	static const level_pair_t levels[] =
	{
		{"DEBUG",	&Harl::debug},
		{"INFO",	&Harl::info},
		{"WARNING",	&Harl::warning},
		{"ERROR",	&Harl::error}
	};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i].str_level == level)
		{
			(this->*(levels[i].action))();
			return;
		}
	}
	std::cout << "Wrong level" << std::endl << std::endl;
}
