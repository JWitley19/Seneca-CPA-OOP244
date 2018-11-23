/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AID_IGOOD_H
#define AID_IGOOD_H

#include <iostream>
#include <fstream>

namespace aid
{
	class iGood
	{
	public:
		// this query will receive a referenceto an fstream object bool and return a reference to the fstream object
		// newLine will specify whether or not a newline should be inserted after each iGood record
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;

		// this modifier will receive a reference to an fstream object and return a reference to that fstream object
		virtual std::fstream& load(std::fstream& file) = 0;

		// this query will receive a reference to an ostream object and a bool (linear) and return a reference to the ostream object
		// linear will specify whether or not the records should be listed on a single line or separate lines
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;

		// this modifier will receive a reference to an istream object and return a reference to the istream object
		virtual std::istream& read(std::istream& is) = 0;

		// this query will receive the address of an unmodifiable C-style null-terminated string and return true if the string 
		// is identical to the sku of an iGood record; false otherwise
		virtual bool operator==(const char*) const = 0;

		// this query will return the cost of a single unit of an iGood with taxes included
		virtual double total_cost() const = 0;

		// this query will return the address of a C-style null-termainated string containing the name of an iGood
		virtual const char* name() const = 0;

		// this modifier will receive an integer holding the number of units of an iGood that are currently available
		// this function will set the number of units available
		virtual void quantity(int) = 0;

		// this query will return an integer holding the number of units of an iGood that are needed
		virtual int qtyNeeded() const = 0;

		// this query will return the number of units of an iGood that are currently available
		virtual int quantity() const = 0;

		// this modifier will receive an integer identifying the number of units to be added to the iGood
		// and return the updated number of units currently available
		virtual int operator+=(int) = 0;

		// this query will receive an unmodifiable reference to an iGood object and returns true if the current object 
		// is greater than the referenced iGood object; false otherwise
		virtual bool operator>(const iGood&) const = 0;

		// destructor
		virtual ~iGood()
		{

		}
	};

	// this helper function will receive a reference to an ostream object and a reference to iGood object and return a reference to an ostream object
	std::ostream& operator<<(std::ostream&, const iGood&);

	// this helper function will receive a reference to an istream object and a reference to an iGood and return a reference to the istream object
	std::istream& operator>>(std::istream&, iGood&);

	// this helper function will receive a reference to a double and an unmodifiable reference to an iGood object and return a double
	double operator+=(double&, const iGood&);

	// this helper function will return the address of a Product object
	iGood* CreateGood();

	// this helper function will return the address of a Perishable object
	iGood* CreatePerishable();
}

#endif //!AID_IGOOD_H
