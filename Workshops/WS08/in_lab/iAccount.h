/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#ifndef _Sict_iAccount_H_
#define _Sict_iAccount_H_

#include <cstring>
#include <string>
#include <iostream>

using namespace std;

namespace sict
{
	class iAccount
	{
	public:
		// adds a positive amount to the account balance
		virtual bool credit(double) = 0;

		// subtracts a positive amount from the account balance
		virtual bool debit(double) = 0;

		// applies month-end transactions to the account
		virtual void monthEnd() = 0;

		// inserts account information into an ostream object
		virtual void display(std::ostream&) const = 0;

		// the destructor for the accounts
		virtual ~iAccount() = default;
	};

	// receives a C-style string identifying the type of account and the initial account balance
	// creates the account with the starting balance and returns its address
	iAccount* CreateAccount(const char* type, double initalBalance);
}

#endif // !_Sict_iAccount_H_
