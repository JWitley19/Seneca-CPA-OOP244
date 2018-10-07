/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 01/10/2018
 **********************************************************/

// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
// TODO: add your headers here

// TODO: continue your namespace here
namespace sict
{
	// TODO: implement the default constructor here

	//Set the Passenger object to a safe empty state

	Passenger::Passenger()
	{
		p_passName[0] = '\0';
		d_dest[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	// check if the strings are valid
	// not empty / not pointing to a null address

	Passenger::Passenger(const char* pName, const char* dest)
	{
		if (pName == nullptr || dest == nullptr)
		{
			*this = Passenger();
		}
		else
		{
			strncpy(p_passName, pName, 31);
			strncpy(d_dest, dest, 31);
		}
	}

	// TODO: implement isEmpty query here
	// the isEmpty query reports if the Passenger objecct is in a safe empty state

	bool Passenger::isEmpty(void) const
	{
		bool valid = strlen(p_passName) > 0 && strlen(d_dest) > 0;
		return !valid;
	}

	// TODO: implement display query here
	// the display query displays the contents of the Passenger object

	void Passenger::display(void) const
	{
		// * If either name or dest is empty
		if (isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << p_passName << " - " << d_dest << endl;
		}
	}
}