// Name: Jordan Witley
// Student Number: 142433176
// 26/09/2018

#ifndef _CRA_ACCOUNT_H_
#define _CRA_ACCOUNT_H_

namespace sict
{
	const int max_name_length = 40; // max number of characters in a name
	const int min_sin = 100000000; // smallest social insurance number
	const int max_sin = 999999999; // largest social insurance number
	const int max_yrs = 4; // maximum number of tax years
	class CRA_Account
	{
		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int m_sin;

		//an array of size max_yrs to hols the tax return years
		int m_year[max_yrs];

		//an array of size max_yrs 
		double m_balance[max_yrs];

		int n_years;

	public:
		void set(const char*, const char*, int);
		void set(int, double);
		void display() const;
		bool isEmpty() const;
	};
}

#endif // _CRA_ACCOUNT_H_



