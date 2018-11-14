/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AMA_ERROR_H
#define AMA_ERROR_H


#include <stdio.h>
#include <iostream>

namespace aid
{
	class Error
	{
	private:
		// this pointer holds the address of the message, if any, stored in the current object
		char* messageAddress; 

	public:
		// receives the address of a C-style null terminated string that holds an error message
		// if the address is nullptr, the functioin puts the object in a safe empty state
		// if the address points to a non-empty message, this function allocates memory for that message
		// and copies the message into the allocated memory
		explicit Error(const char* errorMessage = nullptr);

		// a deleted constructor prevents copying of any ErrorState object
		Error(const Error& em) = delete;

		// a deleted assignment operator prevents assignment of any ErrorState object to the current object
		Error& operator=(const Error& em) = delete;

		// de-allocates any memory that has been dynamically allocated by the current object
		virtual ~Error();

		// clears any message stored by the current object and initializes the object to a safe empty state
		void clear();

		// this query returns true if the current object is in a safe empty state
		bool isClear() const;

		// stores a copy of the C-style string pointed to by str:
		// de-allocated any memory allocated for a previously stored message
		// allocates the dynamic memory needed to store a copy of str (include 1 extra byte for the null terminator)
		// copies the string at address str to the allocated memory
		void message(const char* str);

		// this query returns the address of the message stored on the current object
		const char* message() const;
	};
	// this operator sends an ErrorState message, if one exists, to an std::ostream object and returns a reference to the std::ostream object
	// if no message exists, the operator does not send anything to the std::ostream object and returns a reference to the std::ostream object
	std::ostream& operator<<(std::ostream& ostr, const Error& em);
}

#endif // !AMA_ERROR_H
