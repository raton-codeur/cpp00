#include "Account.hpp"
#include <iostream>

int main()
{
	Account a(42);
	Account b(54);

	Account::displayAccountsInfos();
	a.displayStatus();
	b.displayStatus();

	a.makeDeposit(5);
	b.makeDeposit(765);

	Account::displayAccountsInfos();
	a.displayStatus();
	b.displayStatus();

	a.makeWithdrawal(49);
	b.makeWithdrawal(30);

	Account::displayAccountsInfos();
	a.displayStatus();
	b.displayStatus();
}
