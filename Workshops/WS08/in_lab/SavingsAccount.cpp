/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#include <iostream>
#include "SavingsAccount.h"	

namespace sict
{
	SavingsAccount::SavingsAccount(double initialBalance, double intrstRte) : Account(initialBalance)
	{
		(intrstRte > 0) ? n_intrst = intrstRte : n_intrst = 0.0;
	}

	void SavingsAccount::monthEnd()
	{
		double interest = (balance() * n_intrst);
		credit(interest);
	}

	void SavingsAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Savings" << std::endl;
		ostr.unsetf(std::ios::floatfield);
		ostr.precision(2);
		ostr.setf(std::ios::fixed, std::ios::floatfield);
		ostr << "Balance: $" << balance() << std::endl;
		ostr << "Interest Rate (%): " << n_intrst * 100 << std::endl;
	}
}
