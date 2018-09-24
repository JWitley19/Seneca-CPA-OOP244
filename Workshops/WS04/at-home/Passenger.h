// Name: Jordan Witley
// Date: 03/09/2018

// TODO: add file header comments here

// TODO: add header file guard here
#ifndef Passenger_H_
#define Passenger_H_


// TODO: declare your namespace here
namespace sict
{


	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char passName[32];
		char dest[32];
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
#endif // !Passenger_H_

