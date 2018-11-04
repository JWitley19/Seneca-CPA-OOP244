/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace aid {
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int DAY_ERROR = 2;
	const int MON_ERROR = 3;
	const int YEAR_ERROR = 4;
	const int PAST_ERROR = 5;

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date
	{
	private:
		int n_year, n_month, n_day, n_comparator, n_errorState;
		int mdays(int, int)const;
		void errCode(int errorCode);

	public:
		Date();
		Date(int year, int month, int day);
		int errCode(void) const;
		bool bad(void) const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& ostr, Date&);
	std::istream& operator>>(std::istream& istr, Date&);
}
#endif // !AMA_DATE_H

