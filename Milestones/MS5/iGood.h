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
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
		virtual ~iGood()
		{

		};
	};
	std::ostream& operator<<(std::ostream& os, const iGood& other);
	std::istream& operator>>(std::istream& is, iGood& other);
	double operator+=(double& total, const iGood& other);
	iGood* CreateGood();
	iGood* CreatePerishable();
}

#endif //!AID_IGOOD_H