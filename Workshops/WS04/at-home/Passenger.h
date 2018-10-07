/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/10/2018
 **********************************************************/

 // TODO: add file header comments here

 // TODO: add header file guard here
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_


// TODO: declare your namespace here
namespace sict
{


	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char p_passName[32];
		char d_dest[32];
		int n_year;
		int n_month;
		int n_day;

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		Passenger(const char *, const char *, int, int, int);
		bool isEmpty(void) const;
		void display(void) const;
		const char* name(void) const;
		bool canTravelWith(const Passenger&) const;
	};

}
#endif // !SICT_PASSENGER_H_


