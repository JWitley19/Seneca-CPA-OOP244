// Name: Jordan Witley
// Date: 02/10/2018

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

	public:
		Passenger(void);
		Passenger(const char *, const char *);
		bool isEmpty(void) const;
		void display(void) const;
	};

}
#endif // !Passenger_H_
