/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#include <fstream>
using namespace std;
namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	const int NO_ERROR = 0;//valid data
	const int CIN_FAILED = 1;//istream failed on entering data
	const int DAY_ERROR = 2;//value of day invalid
	const int MON_ERROR = 3;//value of month invalid
	const int YEAR_ERROR = 4;//value of year invalid
	const int PAST_ERROR = 5;//invalid date

	class Date {
		int year, month, day, comparator, error;
		int mdays(int, int)const;
		void errCode(int);
	public:
		Date();
		Date(int, int, int);

		bool operator == (const Date&);
		bool operator != (const Date&);
		bool operator < (const Date&);
		bool operator > (const Date&);
		bool operator <= (const Date&);
		bool operator >= (const Date&);

		int comparatorCalc(int, int, int);
		int errCode() const;
		bool bad() const;
		int returnMonth() const;
		int returnDay() const;
		int returnYear() const;
		std::fstream& store(std::fstream&);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};




}

std::ostream& operator << (std::ostream&, aid::Date&);
std::istream& operator >> (std::istream&, aid::Date&);

#endif
// !AID_DATE_H