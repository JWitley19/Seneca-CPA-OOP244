/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/10/2018
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

 // TODO: add file header comments here
#include <iostream>
#include <cstring>
#include <iomanip>

// TODO: add your headers here
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here

namespace sict
{

	// TODO: implement the default constructor here

	// Sets the Passenger object to a safe empty state 

	Passenger::Passenger()
	{
		p_passName[0] = '\0';
		d_dest[0] = '\0';
		n_year = 0;
		n_month = 0;
		n_day = 0;
	}



	// Check to see if the data is valid - set the departure to October 1 2018

    Passenger::Passenger(const char* pName, const char* destination)
	{
		bool nameInvalid = pName == nullptr;
		bool destInvalid = destination == nullptr;
		bool invalid = nameInvalid && destInvalid;

		if (!invalid)
		{
      strncpy(p_passName,pName,18);
      strncpy(d_dest, destination, 19);
			n_year = 2018;
			n_month = 10;
			n_day = 1;
		}
	}

	// Check to see if the data is valid - copy the data if true

	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day)
	{
		bool yearValid = year >= 2017 && year <= 2020;
		bool monthValid = month >= 1 && month <= 12;
		bool dayValid = day >= 1 && day <= 31;

		if (name == nullptr || destination == nullptr || !yearValid || !monthValid || !dayValid)
		{
			*this = Passenger();
		}
		else
		{
			strncpy(p_passName, name,18);
			strncpy(d_dest, destination, 19);
			n_year = year;
			n_month = month;
			n_day = day;
		}
	}

	// TODO: implement isEmpty query here
	// Check if the Passenger object is empty

	bool Passenger::isEmpty(void) const
	{
		bool valid = strlen(p_passName) > 0 && strlen(d_dest) > 0 && n_day != 0 && n_month != 0 && n_year != 0;
		return !valid;
	}

	// TODO: implement display query here

	void Passenger::display(void) const
	{
		// If the name or destination is empty
		if (isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{
				cout << p_passName << " - " << d_dest << " on " << n_year << "/" << setw(2) << setfill('0') << n_month << "/" << setw(2) << setfill('0') << n_day << endl;
		}
	}

	//TODO: Create .name() method
	const char* Passenger::name(void) const
	{
		return p_passName;
	}

	bool Passenger::canTravelWith(const Passenger& p) const
	{
		bool day = (*this).n_day == p.n_day;
		bool month = (*this).n_month == p.n_month;
		bool year = (*this).n_year == p.n_year;

		bool match = day && month && year;

		return match;
	}

}