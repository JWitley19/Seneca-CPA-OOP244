/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#ifndef _Sict_SavingsAccount_H_
#define _Sict_SavingsAccount_H_

#include <iostream>
#include "Account.h"

namespace sict
{
	class SavingsAccount : public Account
	{
		double n_intrst;
	public:
		// receives the initial balance and the interest rate to be applied to the balance
		// if the interest rate received is positive, the function stores the rate
		// if the interest rate received is negative, the function stores 0.0 as the to be applied 
		SavingsAccount(double initialBalance, double intrstRte);

		// calculates the interest earned on the current balance and credits the account with that interest
		void monthEnd();

		// receives a reference to an ostream object and displays
		void display(std::ostream& ostr) const;
	};
}

#endif // !_Sict_SavingsAccount_H_