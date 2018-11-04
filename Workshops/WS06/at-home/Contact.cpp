/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 02/11/2018
 **********************************************************/

#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
#include "Contact.h"

using namespace sict;

using namespace std;

// sets to a safe empty state
Contact::Contact()
{
	strcpy(n_name, "\0");
	n_numOfPhoneNumbers = 0;
}


// allocates enough memory to hold the data for the created object: name, phoneNumbers, number of phoneNumbers in the array
Contact::Contact(const char* name, long long* phoneNumbers, int numOfPhoneNumbers)
{
	long long numsLeft = 0;
	long long country_code = 0;
	long long area_code = 0;

	int valid[numOfPhoneNumbers];
	
	// checks if the incoming name is null or empty
	bool x_name = name != nullptr; 

	if (x_name)
	{
		strncpy(n_name, name, 20);
		n_name[MAX_CHAR] = '\0';
	}
	else
	{
		*n_name = '\0';
	}

	// checks if the incoming phoneNumber is null or empty
	bool x_phoneNumbers = phoneNumbers != nullptr;

	if (x_phoneNumbers)
	{
		for (int i = 0; i < numOfPhoneNumbers; i++)
		{
			if ((phoneNumbers[i] >= 11001000000 && phoneNumbers[i] <= 99999999999) || (phoneNumbers[i] >= 111001000000 && phoneNumbers[i] <= 999999999999))
			{
				country_code = phoneNumbers[i] / (long long)pow(10, 10);
				area_code = (phoneNumbers[i] / (long long)pow(10, 9)) % 10;
				numsLeft = (phoneNumbers[i] / (long long)pow(10, 6)) % 10;

				if (country_code > 0 && area_code > 0 && numsLeft > 0)
				{
					valid[n_numOfPhoneNumbers] = i;
					n_numOfPhoneNumbers++;
				}
			}
		}

		n_phoneNumbers = new long long[n_numOfPhoneNumbers];
		
		int y = 0;

		for (int i = 0; i < numOfPhoneNumbers; i++)
		{
			if (valid[y] == i)
			{
				n_phoneNumbers[y] = phoneNumbers[i];
				y++;
			}
		}
	}
	else
	{
		n_numOfPhoneNumbers = 0;
	}
}


// returns false if the current object has valid data, true if in a safe emtpy state
bool Contact::isEmpty() const
{
	if(*n_name == '\0')
	{
		return true;
	}
		return false;
}


// displays the data received into the output stream
void Contact::display() const
{
	if (isEmpty())
	{
		cout << "Empty contact!" << endl;
	}
	else
	{
		cout << n_name << endl;

		if (n_phoneNumbers == nullptr)
		{

		}
		else
		{
			for (int i = 0; i < n_numOfPhoneNumbers; i++)
			{
				cout << "(+" << n_phoneNumbers[i] / (long long)pow(10, 10) << ") "
					<< (n_phoneNumbers[i] / (long long)pow(10, 7)) % 1000 << " "
					<< (n_phoneNumbers[i] % (long long)pow(100, 7)) / (long long)pow(10, 4)
					<< "-" << setfill('0') << setw(4) << n_phoneNumbers[i] % 10000 << endl;
			}
		}
	}
}


// deallocates the memory 
Contact::~Contact()
{
	delete[] n_phoneNumbers;
}


// the copy constructor receives an unmodifiable reference to a Contact object copies that object into the newly created instance
Contact::Contact(const Contact& other)
{
	*this = other;
}


// receives a reference to a Contact object and copies the data to the existing object, returns a reference to the current object, as updated
Contact& Contact::operator=(const Contact& rhs)
{
	if (this != &rhs)
	{
		strcpy(n_name, rhs.n_name);

		n_numOfPhoneNumbers = rhs.n_numOfPhoneNumbers;
		delete[] n_phoneNumbers;

		if (rhs.n_phoneNumbers != nullptr)
		{
			n_phoneNumbers = new long long[n_numOfPhoneNumbers];

			for (int i = 0; i < n_numOfPhoneNumbers; i++)
			{
				n_phoneNumbers[i] = rhs.n_phoneNumbers[i];
			}
		}
		else
		{
			n_phoneNumbers = nullptr;
		}
	}

	return *this;
}


// receives a new phone number, and validates the number
Contact& Contact::operator+=(long long phoneNumbers)
{
	long long area_code = 0;
	long long numsLeft = 0;
	long long country_code = 0;
	
	if ((phoneNumbers >= 11001000000 && phoneNumbers <= 99999999999) || (phoneNumbers >= 111001000000 && phoneNumbers <= 999999999999))
	{
		country_code = phoneNumbers / (long long)pow(10, 10);
		area_code = (phoneNumbers / (long long)pow(10, 9)) % 10;
		numsLeft = (phoneNumbers / (long long)pow(10, 6)) % 10;

		if (country_code > 0 && area_code > 0 && numsLeft > 0)
		{
			n_numOfPhoneNumbers++;

			long long* z_phoneNumbers = new long long[n_numOfPhoneNumbers];

			for (int i = 0; i < n_numOfPhoneNumbers - 1; i++)
			{
				if (n_phoneNumbers != nullptr)
				{
					z_phoneNumbers[i] = n_phoneNumbers[i];
				}
			}

			z_phoneNumbers[n_numOfPhoneNumbers - 1] = phoneNumbers;
			delete[] n_phoneNumbers;
			n_phoneNumbers = z_phoneNumbers;
		}
	}

	return *this;
}