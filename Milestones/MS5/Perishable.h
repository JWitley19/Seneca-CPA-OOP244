/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid
{
	class Perishable : public Good
	{
	private:
		Date n_date;
	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
	
}

#endif // !AID_PERISHABLE_H
