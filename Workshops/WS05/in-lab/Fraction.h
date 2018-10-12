/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 07/10/2018
 **********************************************************/

// TODO: header file guard

#ifndef SICT_FRACTION_H_
#define SICT_FRACTION_H_

// TODO: create namespace

namespace sict
{

	// TODO: define the Fraction class
	class Fraction {
	
	private:
	// TODO: declare instance variables

		int n_numerator;
		int n_denominator;

	// TODO: declare private member functions


	public:
	// TODO: declare public member functions

		Fraction(void);
		Fraction(int a, int b);
		int max(void) const;
		int min(void) const;
		void reduce(void);
		int gcd(void) const;
		bool isEmpty(void) const;
		bool isNegative(int x) const;
		void display(void) const;

	// TODO: declare the + operator overload

 		Fraction operator+(const Fraction& rhs) const;
	};
}

#endif // !SICT_FRACTION_H_

