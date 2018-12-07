/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#ifndef AID_ERROR_H
#define AID_ERROR_H


#include <stdio.h>
#include <iostream>

namespace aid
{
	class Error
	{
	private:
		char* n_message;

	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	
	std::ostream& operator<<(std::ostream& ostr, const Error& er);
}

#endif // !AID_ERROR_H