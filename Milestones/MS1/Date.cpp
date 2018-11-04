/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

namespace aid {

	//  set the private data members to a safe empty state
	Date::Date()
	{
		n_year = 00;
		n_month = 00;
		n_day = 00;
		n_comparator = 0;
		n_errorState = NO_ERROR;
	}

	// check if the date is valid and save the sata if it is
	Date::Date(int year, int month, int day)
	{
		bool yearValid = (year >= min_year || year <= max_year) && year > 0;
		int daysInMonth = mdays(month, year);
		bool daysInMonthValid = daysInMonth != 13 && day <= daysInMonth;
		//bool dateValid = (n_comparator = year * 372 + month * 31 + day);

		if (yearValid && daysInMonthValid)
		{
			n_year = year;
			n_month = month;
			n_day = day;
			n_comparator = year * 372 + month * 13 + day;
			//n_comparator >= min_date;
		}
		else
		{
			n_year = 00;
			n_month = 00;
			n_day = 00;
			n_errorState = YEAR_ERROR;
		}
	}

	// sets the error state variable to one of the values listed
	void Date::errCode(int errorCode)
	{
		n_errorState = errorCode;
	}

	// return the error state as an error code value
	int Date::errCode() const
	{
		return n_errorState;
	}

	// return true if n_errorState != NO_ERROR
	bool Date::bad() const
	{
		return n_errorState == NO_ERROR;
	}

	// compare if rhs == this
	bool Date::operator==(const Date& rhs) const
	{
		bool day = this->n_day == rhs.n_day;
		bool month = this->n_month == rhs.n_month;
		bool year = this->n_year == rhs.n_year;

		return(day && month && year);
	}

	// compare if rhs != this
	bool Date::operator!=(const Date& rhs) const
	{
		return !(*this == rhs);
	}

	// check if this < rhs
	bool Date::operator<(const Date& rhs) const
	{
		bool lessYear = this->n_year < rhs.n_year;
		bool lessMonth = this->n_month < rhs.n_month;
		bool lessDay = this->n_day < rhs.n_day;

		if (lessYear)
		{
			return true;
		}
		else if (lessMonth)
		{
			return true;
		}
		else if (lessDay)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// check if this > rhs
	bool Date::operator>(const Date& rhs) const
	{
		return !(*this < rhs);
	}

	// check if theis <= rhs
	bool Date::operator<=(const Date& rhs) const
	{
		return *this < rhs || *this == rhs;
	}

	// check if this >= rhs
	bool Date::operator>=(const Date& rhs) const
	{
		return *this > rhs || *this == rhs;
	}

	// works with an istream object to read a date from the console
	std::istream& Date::read(std::istream& istr)
	{
		char symbol;
		istr.clear();
		istr >> n_year >> symbol >> n_month >> symbol >> n_day;

		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if (n_year > max_year || n_year < min_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
		else if (n_month > 12 || n_month < 1)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (n_day > mdays(n_month, n_year) || n_day < 1)
		{
			*this = Date();
			errCode(DAY_ERROR);
		}
		else if (n_year == 2018 && n_month == 12 && n_day == 29)
		{
			*this = Date();
			errCode(PAST_ERROR);
		}
		return istr;
	}

	// works with an ostream object to print a date to the console
	std::ostream& Date::write(std::ostream& ostr) const
	{
		char symbol = '/';

		// for year
		ostr << n_year << symbol;

		// if the n_month < 10,, add a zero before the month
		if (n_month < 10)
		{
			ostr << 0;
		}
		// in all cases, add the month
		ostr << n_month << symbol;

		if (n_day < 10)
		{
			ostr << 0;
		}

		ostr << n_day;

		// return the output stream that was created
		return ostr;
	}

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	std::istream& operator>>(std::istream& istr, Date& r)
	{
		return r.read(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, Date& e)
	{
		return e.write(ostr);
	}
}
