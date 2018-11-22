/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 16/11/2018
 **********************************************************/

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict
{
	// defines the interest rate
	const double interest = 0.05;
	const double transaction = 0.50;
	const double monthly = 2.00;

	// receives the address of C-style string that identifies the type of account to be created
	// and the initial balance in the account
	// returns the address to the calling function
	// if the initial character of the string is s, the function creates a savings account in dynamic memory
	// if the string does not identify a type that is available, this function returns nullptr
	iAccount* CreateAccount(const char* type, double initialBalance)
	{
		iAccount *p = nullptr;

		if (type[0] == 'S')
		{
			p = new SavingsAccount(initialBalance, interest);
		}
		else if (type[0] == 'C')
		{
			p = new ChequingAccount(initialBalance, transaction, monthly);
		}
		return p;
	}
}