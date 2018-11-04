/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 30/10/2018
 **********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	const int areaCodeLength = 3;
	const int numberLength = 7;
	const int numCodeLength1 = 3;
	const int numCodeLength2 = 4;
	const int MAX_CHAR = 20;
	
	class Contact
	{
		char n_name[MAX_CHAR + 1];
		long long* n_phoneNumbers;
		int n_numOfPhoneNumbers;
		
	private:
		bool isValidPhoneNumber(const long long); // checks if the phone number is valid

	public:
		Contact(); // sets the current object to a safe empty state
		Contact(const char*, const long long*, const int); // allocates enough memory to hold only the valid phone numbers into the allocated array
		~Contact(); // deallocates any memory that has been allocated dynamically
		bool isEmpty() const; // returns false if the current object has valid data, true if in a safe empty state
		void display() const; // displays the data received into the output stream
		// Contact(const Contact& other) = delete; // did not need
		// Contact& operator=(const Contact& other) = delete; // did not need
	};
}
#endif // !SICT_CONTACT_H