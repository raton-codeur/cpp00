#include "Account.hpp"
#include "iostream"
#include <ctime>

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

#include <iomanip>
void Account::_displayTimestamp()
{
	time_t t;

	t = time(NULL);
	std::cout << t << std::endl;
	std::cout << std::put_time(localtime(&t), "[%Y%m%d_%H%M%S]\n");
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