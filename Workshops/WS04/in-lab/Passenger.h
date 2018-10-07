/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 01/10/2018
 **********************************************************/

// TODO: add file header comments here
#ifndef PASSENGER_SICT_H
#define PASSENGER_SICT_H

namespace sict
{

	class Passenger
	{
	private:
		char p_passName[32];
		char d_dest[32];

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		bool isEmpty(void) const;
		void display(void) const;
	};
}

#endif // !PASSENGER_SICT_H