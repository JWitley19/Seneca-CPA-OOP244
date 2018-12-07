/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Section: OOP244SFF
 * Seneca email: jwitley@myseneca.ca
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Error.h"

using namespace std;

namespace aid
{
	Error::Error(const char* errorMessage)
	{
		if (errorMessage != nullptr)
		{
			int length = strlen(errorMessage);
			n_message = new char[length];

			for (int i = 0; i < length; i++)
			{
				n_message[i] = errorMessage[i];
			}
			n_message[length] = '\0';
		}
		else
		{
			n_message = nullptr;
		}

	}

	Error::~Error()
	{
		delete[] n_message;
		n_message = nullptr;
	}

	void Error::clear()
	{
		delete[] n_message;
		n_message = nullptr;
	}

	bool Error::isClear() const
	{
		return (n_message == nullptr) ? true : false;

	}

	void Error::message(const char* str)
	{
		this->~Error();

		if (strlen(str) >= 1)
		{
			n_message = new char[strlen(str) + 1];
			strncpy(n_message, str, strlen(str) + 1);
		}
		else
		{
			n_message = nullptr;
		}
	}

	const char* Error::message() const
	{
		return n_message;
	}

	std::ostream& operator<<(std::ostream& ostr, const Error& em)
	{
		if (!em.isClear())
		{
			ostr << em.message();
		}
		return ostr;
	}
}