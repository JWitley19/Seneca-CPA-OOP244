/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AID_GOOD_H
#define AID_GOOD_H
#include "Error.h"
using namespace std;
namespace aid
{
	const int MAX_CHAR_SKU = 7; // Max number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_UNIT = 10; // Max number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_NAME = 75; // Max number of characters in the user's name description for a Good length
	const double TAX_RATE = 0.13; // The tax rate

	const int max_sku_length = MAX_CHAR_SKU;
	const int max_name_length = MAX_CHAR_NAME;
	const int max_unit_length = MAX_CHAR_UNIT;

	class Good
	{
	private:
		char mg_gd_type; // A character that indicates the type of the Good (for use in the file record)
		char mg_gd_sku[MAX_CHAR_SKU + 1]; // A C-style allocated array that holds the Goods sku (stock keeping unit) - (null char)
		char mg_gd_unit[MAX_CHAR_UNIT + 1]; // A character array that describes the Goods units
		char* mg_addr_gd_name; // A pointer that holds the address of a string in dynamic memory containing the name of the Good
		int mg_qty_gd_onHand; // An integer that holds the quantity of the Good currently on hand; that is, the number of units of the Good currently on hand
		int mg_qty_gd_needed; // An integer that holds the quantity of the Good needed; that is, the number of units of the Good needed
		double mg_price_gd_singleBeforeTax; // A double that holds the price of a single unit of the Good before applying any taxes
		bool mg_gd_taxable; // A bool tha identifies the taxable status of the Good; its value is true if the Good is taxable
		Error mg_error; // An Error object that holds the error of the Good object

	protected:
		void name(const char* name_address); // receives the address of C-style null-terminated string that holds the name of the Good
		const char* name() const; // returns the address of the C-style string that hoolds the name of the Good
		const char* sku() const; // returns the address of the C-style string that holds the sku of the Good
		const char* unit() const; // returns the address of the C-style string that holds the unit of the Good
		bool taxed() const; // returns the taxable status of the Good
		double itemPrice() const; // returns the price of a single item of the Good
		double itemCost() const; // returns the price of a single item of the Good, and tax applies to the Good
		void message(const char*); // receives the address of a C-style null-terminated string holding an error message and stored
		bool isClear() const; // retruns true if the Error object is clear; returns false otherwise

	public:
		Good(char type = 'N'); // constructor optionally receives a character that identifies the Good, default is 'N'

		// saves the data into the object
		Good(const char* sku, const char* address, const char* unit, int onHand = 0, bool taxable = true, double beforeTax = 0.0, int needed = 0);

		Good(const Good& other); // constructor receives an unmodifiable reference to a Product object and copies the object referenced to the current objbect
		
		~Good(); // deallocates any memory that has been dynamically allocated

		// operator receives an unmodifiable reference to a Good object, replaces the current object with a copy of the object that was referred
		Good& operator=(const Good& other);

		// query receives a reference to an fstream object and an optional bool, returns a reference to the fstream object
		std::fstream& store(std::fstream& file, bool newline = true) const;

		std::fstream& load(std::fstream& file); // modifier receives a reference to an fstream object, returns a reference to that fstream object

		// query receives a reference to an ostream object and an optional bool, returns a reference to the ostream object
		std::ostream& write(std::ostream& os, bool linear) const;


		// modifier receives a reference to an istream object, returns a reference to the istream object
		std::istream& read(std::istream& is);

		// query receives the address of an unmodifiable C-Style null-terminated string, returns true if the string is identical to the sku of the current object, otherwie false
		bool operator==(const char* address) const;

		// query returns the total cost of all items of the product on hand, taxes included
		double total_cost() const;

		// modifier receives an integer holding the number of units of the Product that are on hand
		void quantity(int units);
		
		// query returns true if the object is a safe empty statee
		bool isEmpty() const;

		// query returns the number of units of the product that are needed
		int qtyNeeded() const;

		// query returns the number of units of the product that are on hand
		int quantity() const;

		// query receives the address of a C-style null-terminated string holding a product sku, returns true if the sku of the current object is greater than the string stored at the received address
		bool operator>(const char* address) const;

		// query receives an unmodifiable reference to a Product object, returns true if the name of the current object is greater than the name of the referenced Product object, false otherwise
		bool operator>(const Good& other) const;

		// modifier receives an integer identifying the numbers of units to be added to the Product, returns the updated number of units on hand
		int operator+=(int unitsToBeAdded);
	};

	// helper receives a reference to an ostream object and an unmodifiable reference to a Product, returns a reference to the ostream object
	std::ostream& operator<<(std::ostream& os, const Good& other);

	// helper receives a reference to an istream object and a reference to a Product object, returns a reference to the istream object
	std::istream& operator>>(std::istream& is, Good& other);

	// helper receives a reference to a double and an unmodifiable referencce to a Product object, returns a double
	double operator+=(double& total, const Good& other);
}

#endif // !AMA_GOOD_H