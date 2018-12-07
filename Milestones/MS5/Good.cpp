/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "Good.h"

using namespace std;

namespace aid
{
	Good::Good(char type)
	{
		n_type = type;
		n_sku[0] = '\0';
		n_unit[0] = '\0';
		n_name = nullptr;
		n_qty = 0;
		n_needed = 0;
		n_taxable = false;
		n_price = 0.0;
	}

	Good::Good(const char *sku, const char *name, const char *unit, int quantity, bool taxable, double price, int needed)
	{
		bool notNull = sku != nullptr && name != nullptr && unit != nullptr;

		if (notNull)
		{
			strncpy(n_sku, sku, strlen(sku));
			n_sku[strlen(sku)] = '\0';

			Good::name(name);

			strncpy(n_unit, unit, strlen(unit));
			n_unit[strlen(unit)] = '\0';
		}

		n_qty = quantity;
		n_price = price;
		n_needed = needed;
		n_taxable = taxable;
	}

	Good::Good(const Good& other)
	{
		*this = other;
	}

	Good& Good::operator=(const Good& other)
	{
		if (this != &other)
		{
			int sku_l = strlen(other.n_sku);
			int unit_l = strlen(other.n_unit);

			n_type = other.n_type;
			n_needed = other.n_needed;
			n_qty = other.n_qty;
			n_taxable = other.n_taxable;
			n_price = other.n_price;

			name(other.n_name);

			strncpy(n_sku, other.n_sku, sku_l);
			n_sku[sku_l] = '\0';

			strncpy(n_unit, other.n_unit, unit_l);
			n_unit[unit_l] = '\0';
		}
		return *this;
	}

	Good::~Good()
	{
		delete[] n_name;
	}

	// receives a reference to an fstream object and an optional bool and returns a reference to the modified fstream object
	fstream &Good::store(std::fstream &file, bool newline) const
	{
		file << n_type << ',' << n_sku << ',' << n_name << ',' << n_unit << ',' << n_taxable << ',' << n_price << ',' << n_qty << ',' << n_needed;
		if (newline)
		{
			file << endl;
		}
		return file;
	}

	// modifier receives a reference to an fstream object and returns a reference to that fstream object
	fstream &Good::load(std::fstream &file)
	{
		char sku_[MAX_CHAR_SKU];
		char name_[MAX_CHAR_NAME];
		char unit_[MAX_CHAR_UNIT];
		double price;
		int qty;
		int needed;
		char tax;
		bool taxable;

		if (file.is_open())
		{
			file.getline(sku_, MAX_CHAR_SKU, ',');
			sku_[strlen(sku_)] = '\0';

			file.getline(name_, MAX_CHAR_NAME, ',');
			name_[strlen(name_)] = '\0';

			file.getline(unit_, MAX_CHAR_UNIT, ',');
			unit_[strlen(unit_)] = '\0';

			file >> tax;

			if (tax == '1')
			{
				taxable = true;
			}
			else if (tax == '0')
			{
				taxable = false;
			}

			file.ignore();
			file >> price;
			file.ignore();
			file >> qty;
			file.ignore();
			file >> needed;
			file.ignore();

			*this = Good(sku_, name_, unit_, qty, taxable, price, needed);
		}
		return file;
	}

	// query receives a reference to an ostream object and a bool flag and returns a reference to the modified ostream object
	ostream &Good::write(std::ostream &os, bool linear) const
	{
		if (!(er.isClear()))
		{
			os << er.message();
		}

		else if (linear)
		{
			os << setw(MAX_CHAR_SKU) << left << n_sku << '|'
				<< setw(20) << left << n_name << '|'
				<< setw(7) << right << fixed << setprecision(2) << itemCost() << '|'
				<< setw(4) << right << n_qty << '|'
				<< setw(10) << left << n_unit << '|'
				<< setw(4) << right << n_needed << '|';
		}
		else
		{
			os << " Sku: " << n_sku << endl
				<< " Name (no spaces): " << n_name << endl
				<< " Price: " << n_price << endl;

			if (n_taxable)
			{
				os << " Price after tax: " << itemCost() << endl;
			}
			else
			{
				os << " Price after tax:  N/A" << endl;
			}

			os << " Quantity on Hand: " << n_qty << ' ' << n_unit << endl
				<< " Quantity needed: " << n_needed;
		}
		return os;
	}

	istream &Good::read(std::istream &is)
	{
		char taxed;
		char * address = new char[MAX_CHAR_NAME + 1];
		int qty, need;
		double _price;

		if (!is.fail())
		{
			cout << " Sku: ";
			is >> n_sku;
			cin.ignore();

			cout << " Name (no spaces): ";
			is >> address;
			name(address);

			cout << " Unit: ";
			is >> n_unit;

			cout << " Taxed? (y/n): ";
			is >> taxed;

			if (!is.fail())
			{
				er.clear();

				if (taxed)
				{
					bool yValid = taxed == 'y' || taxed == 'Y';
					bool nValid = taxed == 'n' || taxed == 'N';

					if (yValid)
					{
						n_taxable = true;
					}

					if (nValid)
					{
						n_taxable = false;
					}

					if (!(yValid || nValid))
					{
						is.setstate(std::ios::failbit);
						er.message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}
			}
			else
			{
				is.setstate(std::ios::failbit);
				er.message("Only (Y)es or (N)o are acceptable");
				return is;
			}

			cout << " Price: ";
			is >> _price;

			if (is.fail())
			{
				er.clear();
				is.setstate(ios::failbit);
				er.message("Invalid Price Entry");
				return is;
			}
			else
			{
				price(_price);
			}

			cout << " Quantity on hand: ";
			is >> qty;

			if (is.fail())
			{
				er.clear();
				er.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
			{
				quantity(qty);
			}

			cout << " Quantity needed: ";
			is >> need;
			cin.ignore();

			if (is.fail())
			{
				er.clear();
				er.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
			{
				needed(need);
			}

			if (!is.fail())
			{
				er.clear();
			}
		}
		return is;
	}

	// checks if the parameter == the sku of the current object
	bool Good::operator==(const char *rhs) const
	{
		if (rhs == sku())
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	double Good::total_cost() const
	{
		return n_qty * itemCost();
	}

	void Good::quantity(int quantity)
	{
		n_qty = quantity;
	}

	void Good::price(double price)
	{
		n_price = price;
	}

	void Good::needed(int needed)
	{
		n_needed = needed;
	}

	bool Good::isEmpty() const
	{
		if (n_name == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	char Good::type() const
	{
		return n_type;
	}

	int Good::qtyNeeded() const
	{
		return n_needed;
	}

	int Good::quantity() const
	{
		return n_qty;
	}

	bool Good::operator>(const char* rhs) const
	{
		if (strcmp(n_sku, rhs) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Good::operator>(const iGood& rhs) const
	{
		if (strcmp(n_name, rhs.name()) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Good::operator+=(int units)
	{
		if (units > 0)
		{
			n_qty += units;
			return n_qty;
		}
		else
		{
			return n_qty;
		}
	}

	void Good::name(const char* name)
	{
		if (name != nullptr)
		{
			int length = strlen(name);
			n_name = new char[length + 1];

			for (int i = 0; i < length; i++)
			{
				n_name[i] = name[i];
			}
			n_name[length] = '\0';
		}
		else if (name == nullptr)
		{
			delete[] n_name;
			n_name = nullptr;
		}
	}

	const char* Good::name() const
	{
		if (n_name != nullptr)
		{
			return n_name;
		}
		else
		{
			return nullptr;
		}
	}

	const char* Good::sku() const
	{
		return n_sku;
	}

	const char* Good::unit() const
	{
		return n_unit;
	}

	bool Good::taxed() const
	{
		return n_taxable;
	}

	double Good::itemPrice() const
	{
		return n_price;
	}

	double Good::itemCost() const
	{
		if (n_taxable)
		{
			return itemPrice() * (TAX_RATE + 1);
		}
		else
		{
			return itemPrice();
		}
	}

	void Good::message(const char* errorMessage)
	{
		if (errorMessage != nullptr)
		{
			er.message(errorMessage);
		}
	}

	bool Good::isClear() const
	{
		return er.isClear();
	}

	std::ostream& operator<<(std::ostream& os, const iGood& other)
	{
		return other.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iGood& other)
	{
		return other.read(is);
	}

	double operator+=(double& total, const iGood& other)
	{
		return total += other.total_cost();
	}

}
