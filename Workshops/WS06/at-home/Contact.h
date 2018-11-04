/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 31/10/2018
 **********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <stdio.h>

namespace sict
{
	const int MAX_CHAR = 20;

	class Contact
	{
		char n_name[MAX_CHAR + 1];
		long long* n_phoneNumbers;
		int n_numOfPhoneNumbers;

	private:
		//bool isValidPhoneNumber(const long long); // checks if the phone number is valid

	public:
		Contact(); // sets the current object to a safe empty state
		Contact(const char*, long long*, int); // allocates enough memory to hold only the valid phone numbers into the allocated array
		~Contact(); // deallocates any memory that has been allocated dynamically
		bool isEmpty() const; // returns false if the current object has valid data, true if in a safe empty state
		void display() const; // displays the data received into the output stream
		Contact(const Contact& other); // copy constructor which receives an unmodifiable reference to a Contact object copies that object into the newly created instance
		Contact& operator=(const Contact& rhs); // receives reference to a Contact object and copies the data to the existing object, returns a reference to the current object, as updated
		Contact& operator+=(long long phoneNumber); // receives a new phone number, validates the number
	};
}
#endif // !SICT_CONTACT_H
