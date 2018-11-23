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
		if (errorMessage == nullptr)
		{
			messageAddress = nullptr;
		}
		else if (strlen(errorMessage) == 0)
		{
			messageAddress = nullptr;
		}
		else
		{
			messageAddress = new char[strlen(errorMessage) + 1];
			strcpy(messageAddress, errorMessage);
		}

	}

	Error::~Error()
	{
		delete[] messageAddress;
		messageAddress = nullptr;
	}

	void Error::clear()
	{
		delete[] this->messageAddress;
		messageAddress = nullptr;
	}

	bool Error::isClear() const
	{
		return (messageAddress == nullptr) ? true : false;

	}

	void Error::message(const char* str)
	{
		/*delete[] messageAddress;
		messageAddress = new char[strlen(str) + 1];
		strcpy(messageAddress, str);*/

		this->~Error();

		if (strlen(str) >= 1)
		{
			messageAddress = new char[strlen(str) + 1];
			strncpy(messageAddress, str, strlen(str) + 1);
		}
		else
		{
			messageAddress = nullptr;
		}

		/*if (messageAddress != nullptr)
		{
			delete[] messageAddress;
			messageAddress = nullptr;
		}

		if (str == nullptr)
		{
			messageAddress = nullptr;
		}
		else if(strlen(str) == 0)
		{
			messageAddress = nullptr;
		}
		else
		{
			int plusOne = (int)strlen(str) + 1;
			messageAddress = new char[plusOne];
			strncpy(messageAddress, str, plusOne);
			messageAddress[plusOne + 1] = '\0';
		}*/
	}

	const char* Error::message() const
	{
		if (messageAddress != nullptr)
		{
			return messageAddress;
		}

		return messageAddress;
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