/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 16/11/2018
 **********************************************************/

#include "ChequingAccount.h"

using namespace std;

namespace sict
{
	// this constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double initialBalance, double transactionFee, double monthEndFee) : Account(initialBalance)
	{
		(transactionFee > 0) ? t_transaction = transactionFee : t_transaction = 0.0;
		(monthEndFee > 0) ? m_monthEnd = monthEndFee : m_monthEnd = 0.0;
	}

	// credit (adds) an amount to the account balance and charge fee
	// returns bool to indicate whether money was credited
	bool ChequingAccount::credit(double amntToCredit)
	{
		Account::debit(t_transaction);
		return Account::credit(amntToCredit);
	}

	// debit (subtracts) an amount from the account balance and charge fee
	// returns bool to indicate whether money was debited
	bool ChequingAccount::debit(double amntToDebit)
	{
		return Account::debit(amntToDebit + t_transaction);
	}

	// debits the month end fee
	void ChequingAccount::monthEnd()
	{
		Account::debit(m_monthEnd);
	}

	// inserts the account information into ostream ostr
	void ChequingAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Chequing" << std::endl;
		ostr.unsetf(std::ios::floatfield);
		ostr.precision(2);
		ostr.setf(std::ios::fixed, std::ios::floatfield);
		ostr << "Balance: $" << balance() << std::endl;
		ostr << "Per Transaction Fee: " << t_transaction << std::endl;
		ostr << "Monthly Fee: " << m_monthEnd << std::endl;
	}
}