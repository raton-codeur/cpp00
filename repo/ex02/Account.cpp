#include "Account.hpp"
#include "iostream"
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp()
{
	time_t		now;
	struct tm*	tm;

	time(&now);
	tm = localtime(&now);
	std::cout	<< "[" << std::setfill('0')
				<< tm->tm_year + 1900
				<< std::setw(2) << tm->tm_mon + 1
				<< std::setw(2) << tm->tm_mday
				<< "_"
				<< std::setw(2) << tm->tm_hour
				<< std::setw(2) << tm->tm_min
				<< std::setw(2) << tm->tm_sec
				<< "] ";
}

// void	displayAccountsInfos( void );

// fin des trucs statiques


Account::Account(int initial_deposit) :
	_amount(initial_deposit)
{
	Account::_displayTimestamp();
}

Account::~Account() {}




// void	makeDeposit( int deposit );
// bool	makeWithdrawal( int withdrawal );
// int		checkAmount( void ) const;
// void	displayStatus( void ) const;