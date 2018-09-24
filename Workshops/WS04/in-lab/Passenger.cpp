// Name: Jordan Witley
// Date: 02/10/2018

#define _CRT_SECURE_NO_WARNINGS

// TODO: add file header comments here
#include <iostream>
#include <cstring>

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
		passName[0] = '\0';
		dest[0] = '\0';
	}

	
	// TODO: implement the constructor with 2 parameters here
	// Check to see if the data is valid - copy the data if true

	Passenger::Passenger(const char* pName, const char* destination)
	{
		if (pName == nullptr || destination == nullptr)
		{
			*this = Passenger();
		}
		else
		{
			strcpy(passName, pName);
			strcpy(dest, destination);
		}
	}

	
	// TODO: implement isEmpty query here
	// Check if the Passenger object is empty

	bool Passenger::isEmpty(void) const
	{
		bool valid = strlen(passName) > 0 && strlen(dest) > 0;
		return !valid;
	}
	
	// TODO: implement display query here

	void Passenger::display(void) const
	{
		// If the name or destination is empty
		if (passName[0] == '\0' || dest[0] == '\0')
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << passName << " - " << dest << endl;
		}
	}
}