/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 30/10/2018
 **********************************************************/

#include <cstring>
#include <iostream>
#include "Contact.h"

using namespace std;

namespace sict
{
	// check if the phone number is valid 
	bool Contact::isValidPhoneNumber(const long long phoneNumber)
	{
		string phoneNumberString = to_string(phoneNumber);
		bool invalid = phoneNumber <= 0 || phoneNumberString.length() < 11 || phoneNumberString.length() > 12 || phoneNumberString[phoneNumberString.length() - 7] == '0' || phoneNumberString[phoneNumberString.length() - 10] == '0';
		return !invalid;
	}

	// returns false if the current object has valid data; true if the 
	bool Contact::isEmpty() const
	{
		return (n_name[0] == '\0' && n_phoneNumbers == nullptr && n_numOfPhoneNumbers == 0) ? true : false;
	}

	// sets the current object to a safe empty state
	Contact::Contact()
	{
		n_name[0] = '\0';
		n_numOfPhoneNumbers = 0;
		n_phoneNumbers = nullptr;
	}

	// allocates enough memory to hold only the valid phone numbers into the allocated array
	Contact::Contact(const char* name, const long long* phoneNumbers, const int numOfPhoneNumbers)
	{
		if (name != nullptr && name[0] != '\0')
		{
			int sizeOf_n_name = (sizeof(n_name) - 1);
			int parameter_name_length = strlen(name);
			int n_name_length = (parameter_name_length > sizeOf_n_name) ? sizeOf_n_name : parameter_name_length;
			
			for (int i = 0; i < n_name_length; i++)
			{
				n_name[i] = name[i];
			}
			n_name[n_name_length] = '\0';
		}
		else
		{
			n_name[0] = '\0';
		}

		if (phoneNumbers != nullptr || numOfPhoneNumbers > 0)
		{
			if (phoneNumbers != nullptr)
			{
				n_phoneNumbers = new long long[numOfPhoneNumbers];
				n_numOfPhoneNumbers = 0;

				for (int phone = 0; phone < numOfPhoneNumbers; phone++)
				{
					if (isValidPhoneNumber(phoneNumbers[phone]))
					{
						n_numOfPhoneNumbers += 1;
						n_phoneNumbers[n_numOfPhoneNumbers - 1] = phoneNumbers[phone];
					}
				}
			}
		}
		else
		{
			n_phoneNumbers = nullptr;
			n_numOfPhoneNumbers = 0;
		}
	}
	
	// displays the data received into the output stream
	void Contact::display() const
	{
		string country_Code;
		string area_Code;
		string number_Code1;
		string number_Code2;
		string phoneNumberString;
		int phoneNumberStringLength;

		if (!isEmpty())
		{
			cout << n_name << endl;

			for (int phone = 0; phone < n_numOfPhoneNumbers; phone++) 
			{
				phoneNumberString = to_string(n_phoneNumbers[phone]);
				phoneNumberStringLength = phoneNumberString.length();
				country_Code = phoneNumberString.substr(0, (phoneNumberStringLength - (areaCodeLength + numberLength)));
				area_Code = phoneNumberString.substr(phoneNumberStringLength - (areaCodeLength + numberLength), areaCodeLength);
				number_Code1 = phoneNumberString.substr(phoneNumberStringLength - numberLength, numCodeLength1);
				number_Code2 = phoneNumberString.substr(phoneNumberStringLength - numCodeLength2, numCodeLength2);

				cout << "(+" << country_Code << ")" << " " << area_Code << " " << number_Code1 << "-" << number_Code2 << endl;
			}
		}
		else
		{
			cout << "Empty contact!" << endl;
		}
	}

	// deallocator
	Contact::~Contact()
	{
		// deallocates the n_phoneNumbers
		if (n_phoneNumbers != nullptr)
		{
			delete[] n_phoneNumbers;
			n_phoneNumbers = nullptr;
		}
	}
}