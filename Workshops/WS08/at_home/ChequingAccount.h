/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 16/11/2018
 **********************************************************/

#ifndef Sict_ChequingAccount_H_
#define Sict_ChequingAccount_H_

#include "Account.h"

namespace sict
{
	class ChequingAccount : public Account
	{
		double t_transaction;
		double m_monthEnd;

	public:
		// if the tax fee received is positive, the function stores the fee
		// if the tax fee is negative, the function stores 0.0 as the fee
		ChequingAccount(double initialBalance, double transactionFee, double monthEndFee);

		// credits the balance by the amount passed, if successful return true
		bool credit(double amntToCredit);

		// debits the balance with the amount that was passed, if successful return true
		bool debit(double amntToDebit);

		// debits the monthly fee from the balance
		void monthEnd();

		// receives a reference to an ostream object
		// inserts the accouont information into an ostream
		void display(std::ostream& ostr) const;
	};
}
#endif

