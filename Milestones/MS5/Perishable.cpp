/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#include <iostream>
#include "Perishable.h"

using namespace std;

namespace aid
{
	Perishable::Perishable() : Good('P')
	{
		er.clear();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		/*Good::store(file, false);
		file << ',';
		n_date.write(file);
			
		if (newLine)
			{
				file << endl;
			}
		
		return file;*/
		Date temp = n_date;
		Good::store(file, false);
		file << ",";
		temp.write(file);
		if (newLine) {
			file << std::endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file)
	{
		Good::load(file);
		n_date.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		Good::write(os, linear);

		if (isClear() && !isEmpty())
		{
			if (linear)
			{
				n_date.write(os);
			}
			else
			{
				os << "\n Expiry date: ";
				n_date.write(os);
			}
		}

		return os;
	}

	std::istream& Perishable::read(std::istream& is)
	{
		is.clear();
		Good::read(is);

		if (er.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			n_date.read(is);
		}

		if (n_date.errCode() == CIN_FAILED)
		{
			er.clear();
			er.message("Invalid Date Entry");
		}

		if (n_date.errCode() == YEAR_ERROR)
		{
			er.message("Invalid Year in Date Entry");
		}

		if (n_date.errCode() == MON_ERROR)
		{
			er.clear();
			er.message("Invalid Month in Date Entry");
		}

		if (n_date.errCode() == DAY_ERROR)
		{
			er.clear();
			er.message("Invalid Day in Date Entry");
		}

		if (n_date.errCode() == PAST_ERROR)
		{
			er.clear();
			er.message("Invalid Expiry in Date Entry");
		}

		if (n_date.errCode())
		{
			is.setstate(std::ios::failbit);
		}

		if (n_date.errCode() != CIN_FAILED && n_date.errCode() != YEAR_ERROR && n_date.errCode() != MON_ERROR && n_date.errCode() != DAY_ERROR && n_date.errCode() != PAST_ERROR)
		{
			er.clear();
		}

		return is;
	}

	const Date& Perishable::expiry() const
	{
		return n_date;
	}

}