/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 16/11/2018
 **********************************************************/

#ifndef _Sict_Account_H_
#define _Sict_Account_H_

#include "iAccount.h"

namespace sict
{
	class Account : public iAccount
	{
		double n_balance;
	protected:
		//returns the current balance of the account
		double balance() const;

	public:
		// this constructor receives either a double holding the initial account or nothing
		// if the amount received is positive-valued, this function initializes the current 
		// account balance to the received amount
		// if the amount received is not positive-valued or no amount is received, this function
		// initialzes the current balance to 0.0
		Account(double initialBalance);

		// receives an amount to be credited(added) to the account balance and returns the success
		// of the transaction
		// if the amount received is positive-valued, the transaction succeeds and this function 
		// adds the amount received to the current balance
		// if the amount is not positive-valued, the transaction fails and this function does not
		// add the amount received
		bool credit(double amntToAdd);

		// receives an amount to be debited (subtracted) from the account balance and returns the 
		// success of the transaction
		// if the amount received is positive-valued, the transaction succeeds and thhis function 
		// subtracts the amount received from the current balance
		// if the amount is not positive-valued, the transaction fails and this function does not
		// s the amouunt received
		bool debit(double amntToSbtrct);
	};

	// prototype allocator for function
	iAccount* CreateAccount(const char* type, double initialBalance);
}

#endif // !_Sict_Account_H_


