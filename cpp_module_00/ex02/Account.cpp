#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm *tm = std::localtime(&now);
	std::cout
		<< '['
		<< tm->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << tm->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << tm->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << tm->tm_hour
		<< std::setw(2) << std::setfill('0') << tm->tm_min
		<< std::setw(2) << std::setfill('0') << tm->tm_sec
		<< ']';
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";closed\n";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:"
		<< _nbAccounts
		<< ";total:"
		<< _totalAmount
		<< ";deposits:"
		<< _totalNbDeposits
		<< ";withdrawals:"
		<< _totalNbWithdrawals
		<< '\n';
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";deposit:"
		<< deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout
		<< ";amount:"
		<< _amount
		<< ";nb_deposits:"
		<< _nbDeposits
		<< '\n';
	return;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout
		<< withdrawal
		<< ";amount:"
		<< _amount
		<< ";nb_withdrawals:"
		<< _nbWithdrawals
		<< '\n';
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";deposits:"
		<< _nbDeposits
		<< ";withdrawals:"
		<< _nbWithdrawals
		<< '\n';
}
