/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Error.h"
#include "Good.h"

using namespace std;

namespace aid
{
	Good::Good(char type)
	{
		mg_gd_type = type;
		mg_gd_sku[0] = '\0';
		mg_gd_unit[0] = '\0';
		mg_addr_gd_name = nullptr;
		mg_qty_gd_onHand = 0;
		mg_qty_gd_needed = 0;
		mg_gd_taxable = false;
		mg_price_gd_singleBeforeTax = 0.0;
	}

	Good::Good(const char *sku, const char *address, const char *unit, int onHand, bool taxable, double beforeTax, int needed)
	{
		name(address);
		strncpy(mg_gd_sku, sku, max_sku_length);
		mg_gd_sku[max_sku_length] = '\0';

		strncpy(mg_gd_unit, unit, max_unit_length);
		mg_gd_unit[max_unit_length] = '\0';

		mg_qty_gd_onHand = onHand;
		mg_qty_gd_needed = needed;
		mg_gd_taxable = taxable;
		mg_price_gd_singleBeforeTax = beforeTax;
	}

	Good::~Good()
	{
		delete[] mg_addr_gd_name;
	}

	Good::Good(const Good& other)
	{
		int length = strlen(other.mg_addr_gd_name);

		mg_gd_type = other.mg_gd_type;

		strncpy(mg_gd_sku, other.mg_gd_sku, max_sku_length);
		mg_gd_sku[max_sku_length] = '\0';

		strncpy(mg_gd_unit, other.mg_gd_unit, max_unit_length);
		mg_gd_unit[max_unit_length] = '\0';

		mg_qty_gd_needed = other.mg_qty_gd_needed;
		mg_qty_gd_onHand = other.mg_qty_gd_onHand;
		mg_gd_taxable = other.mg_gd_taxable;
		mg_price_gd_singleBeforeTax = other.mg_price_gd_singleBeforeTax;

		if (other.mg_addr_gd_name != nullptr)
		{
			mg_addr_gd_name = nullptr;
			mg_addr_gd_name = new char[length];

			for (int i = 0; i < length; i++)
			{
				mg_addr_gd_name[i] = other.mg_addr_gd_name[i];
			}

			mg_addr_gd_name[length] = '\0';
		}
		else
		{
			mg_addr_gd_name = nullptr;
		}
	}

	void Good::name(const char* name_address)
	{
		if (name_address != nullptr)
		{
			int length = strlen(name_address);

			mg_addr_gd_name = new char[length];

			for (int i = 0; i < length; i++)
			{
				mg_addr_gd_name[i] = name_address[i];
			}

			mg_addr_gd_name[length] = '\0';
		}
	}

	const char *Good::name() const
	{
		return (mg_addr_gd_name[0] == '\0') ? nullptr : mg_addr_gd_name;
	}

	const char *Good::sku() const
	{
		return mg_gd_sku;
	}

	const char *Good::unit() const
	{
		return mg_gd_unit;
	}

	bool Good::taxed() const
	{
		return mg_gd_taxable;
	}

	double Good::itemPrice() const
	{
		return mg_price_gd_singleBeforeTax;
	}

	double Good::itemCost() const
	{
		return (mg_gd_taxable) ? itemPrice() * (TAX_RATE + 1) : itemPrice();
	}

	void Good::message(const char *address_error)
	{
		mg_error.message(address_error);
	}

	bool Good::isClear() const
	{
		return mg_error.isClear();
	}

	Good &Good::operator=(const Good &other)
	{
		if (this != &other)
		{
			mg_gd_type = other.mg_gd_type;

			strncpy(mg_gd_sku, other.sku(), max_sku_length);
			strncpy(mg_gd_unit, other.unit(), max_unit_length);

			mg_qty_gd_needed = other.mg_qty_gd_needed;
			mg_qty_gd_onHand = other.mg_qty_gd_onHand;
			mg_gd_taxable = other.mg_gd_taxable;
			mg_price_gd_singleBeforeTax = other.mg_price_gd_singleBeforeTax;

			delete[] mg_addr_gd_name;

			if (other.mg_addr_gd_name != nullptr)
			{
				int length = strlen(other.mg_addr_gd_name);
				mg_addr_gd_name = new char[length];

				for (int i = 0; i < length; i++)
				{
					mg_addr_gd_name[i] = other.mg_addr_gd_name[i];
				}
				mg_addr_gd_name[length] = '\0';
			}
			else
			{
				mg_addr_gd_name = nullptr;
			}
		}

		return *this;
	}

	fstream &Good::store(std::fstream &file, bool newline) const
	{
		file << mg_gd_type << ',' << mg_gd_sku << ',' << mg_gd_unit << ',' << mg_addr_gd_name << ',' << mg_qty_gd_onHand << ',' << mg_gd_taxable << ',' << mg_price_gd_singleBeforeTax << ',' << mg_qty_gd_needed;
		if (newline)
			file << endl;
		return file;
	}

	fstream &Good::load(std::fstream &file)
	{
		Good temp;

		temp.mg_addr_gd_name = new char[MAX_CHAR_NAME + 1];

		if (file.is_open())
		{
			file >> temp.mg_gd_type >> temp.mg_gd_sku >> temp.mg_gd_unit >> temp.mg_addr_gd_name >> temp.mg_qty_gd_onHand >> temp.mg_gd_taxable >> temp.mg_price_gd_singleBeforeTax >> temp.mg_qty_gd_needed;
			*this = temp;
		}

		delete[] temp.mg_addr_gd_name;
		temp.mg_addr_gd_name = nullptr;

		return file;
	}

	ostream &Good::write(std::ostream &os, bool linear) const
	{
		// this will insert the data fields for the current object into the ostream object in the following order
		// and separates them by a vertical bar ('|')
		// if the bool parameter is true, the output will be on a single line with the field widths as shown below in parentheses
		if (linear)
		{
			os << setw(MAX_CHAR_SKU) << left << mg_gd_sku << '|'
				<< setw(20) << left << mg_addr_gd_name << '|'
				<< setw(7) << right << fixed << setprecision(2) << itemCost() << '|'
				<< setw(4) << right << mg_qty_gd_onHand << '|'
				<< setw(10) << left << mg_gd_unit << '|'
				<< setw(4) << right << mg_qty_gd_needed << '|';
		}
		else
		{
			os << "Sku: " << mg_gd_sku << "|" << endl
				<< "Name: " << mg_addr_gd_name << "|" << endl
				<< "Price: " << mg_price_gd_singleBeforeTax << "|" << endl;
			if (mg_gd_taxable)
			{
				os << "Price after tax: " << itemCost() << "|" << endl;
			}
			else
			{
				os << "N/A"
					<< "|" << endl;
			}

			os << "Quantity On hand: " << mg_qty_gd_onHand << "|" << endl
				<< "Quantity needed: " << mg_qty_gd_needed << "|" << endl;
		}
		return os;
	}

	istream &Good::read(std::istream &is)
	{
		char sku[MAX_CHAR_SKU + 1];
		char *address = new char[MAX_CHAR_NAME + 1];
		char unit[MAX_CHAR_UNIT + 1];
		int onHand;
		int needed;
		double before_tax;
		char tax;
		bool taxable;
		Error error;

		cout << " Sku: ";
		is >> sku;

		cout << " Name (no spaces): ";
		is >> address;

		cout << " Unit: ";
		is >> unit;

		cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'Y' || tax == 'y')
		{
			taxable = true;
		}
		else if (tax == 'N' || tax == 'n')
		{
			taxable = false;
		}
		else
		{
			is.setstate(std::ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> before_tax;

			if (is.fail())
			{
				error.message("Invalid Price Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> onHand;

			if (is.fail())
			{
				error.message("Invalid Quantity Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
			{
				error.message("Invalid Quantity Needed Entry");
			}
		}

		// checks if there aare no error messages - if the istream object has accepted all input successfully
		// stores the input values accepted in a temporary object
		// copy assigns it to the current object
		if (!is.fail())
		{
			Good temp = Good(sku, address, unit, onHand, taxable, before_tax, needed);
			*this = temp;
		}
		delete[] address;
		address = nullptr;
		return is;
	}

	// checks if the parameter == the sku of the current object
	bool Good::operator==(const char *address) const
	{
		return strcmp(address, this->mg_gd_sku) == 0;
	}

	double Good::total_cost() const
	{
		double taxed = mg_price_gd_singleBeforeTax * TAX_RATE;
		double withTax = mg_price_gd_singleBeforeTax + taxed;
		return static_cast<double>(mg_qty_gd_onHand * withTax);
	}

	void Good::quantity(int units)
	{
		mg_qty_gd_onHand = units;
	}

	bool Good::isEmpty() const
	{
		return (mg_addr_gd_name == nullptr) ? true : false;
	}

	int Good::qtyNeeded() const
	{
		return mg_qty_gd_needed;
	}

	int Good::quantity() const
	{
		return mg_qty_gd_onHand;
	}

	bool Good::operator>(const char *address) const
	{
		return (strcmp(mg_gd_sku, address) > 0) ? true : false;
	}

	bool Good::operator>(const Good &other) const
	{
		return (strcmp(mg_addr_gd_name, other.mg_addr_gd_name) > 0) ? true : false;
	}

	int Good::operator+=(int unitsToBeAdded)
	{
		if (unitsToBeAdded > 0)
		{
			mg_qty_gd_onHand += unitsToBeAdded;
			return mg_qty_gd_onHand;
		}
		else
		{
			return mg_qty_gd_onHand;
		}
	}

	ostream &operator<<(std::ostream &os, const Good &other)
	{
		return other.write(os, true);
	}

	istream &operator>>(std::istream &is, Good &other)
	{
		other.read(is);
		return is;
	}

	double operator+=(double &total, const Good &other)
	{
		return total + other.total_cost();
	}
}
