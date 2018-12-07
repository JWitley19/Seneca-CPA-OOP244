/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include <iostream>

#include "iGood.h"
#include "Error.h"

using namespace std;

namespace aid
{
	const int MAX_CHAR_SKU = 7; 
	const int MAX_CHAR_UNIT = 10;
	const int MAX_CHAR_NAME = 75;
	const double TAX_RATE = 0.13;

	const int max_sku_length = MAX_CHAR_SKU;
	const int max_name_length = MAX_CHAR_NAME;
	const int max_unit_length = MAX_CHAR_UNIT;

	class Good : public iGood
	{
		char n_type;
		char n_sku[MAX_CHAR_SKU + 1]; 
		char n_unit[MAX_CHAR_UNIT + 1]; 
		char* n_name; 
		int n_qty; 
		int n_needed; 
		double n_price; 
		bool n_taxable;  

	protected:
		Error er;
		void name(const char* name);
		const char* name() const; 
		const char* sku() const; 
		const char* unit() const; 
		bool taxed() const; 
		double itemPrice() const; 
		double itemCost() const; 
		void message(const char* errorMessage);
		bool isClear() const; 

	public:
		Good(char type = 'N'); 
		Good(const char* sku, const char* name, const char* unit, int quantity = 0, bool taxable = true, double price = 0.0, int needed = 0);
		Good(const Good& other); 
		~Good(); 
		Good& operator=(const Good& other);
		std::fstream& store(std::fstream& file, bool newline = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* rhs) const;
		double total_cost() const;
		void quantity(int quantity);
		void price(double price);
		bool isEmpty() const;
		void needed(int needed);
		char type() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* rhs) const;
		bool operator>(const iGood& rhs) const;
		int operator+=(int units);
	};
	std::ostream& operator<<(std::ostream& os, const iGood& other);
	std::istream& operator>>(std::istream& is, iGood& other);
	double operator+=(double& total, const iGood& other);
	iGood* CreateGood();
}

#endif // !AMA_GOOD_H