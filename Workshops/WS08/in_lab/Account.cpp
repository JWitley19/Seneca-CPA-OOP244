/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict
{
	Account::Account(double initialBalance)
	{
		(initialBalance) ? n_balance = initialBalance : n_balance = 0;
	}

	bool Account::credit(double amntToAdd)
	{
		if (amntToAdd > 0)
		{
			n_balance += amntToAdd;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Account::debit(double amntToSbtrct)
	{
		if (amntToSbtrct > 0)
		{
			n_balance -= amntToSbtrct;
			return true;
		}
		else
		{
			return false;
		}
	}

	double Account::balance() const
	{
		return n_balance;
	}

}