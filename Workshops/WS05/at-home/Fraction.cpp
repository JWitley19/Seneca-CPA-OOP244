/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 11/10/2018
 **********************************************************/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"	

using namespace std;

namespace sict
{


	Fraction::Fraction(void)
	{
		n_numerator = 0;
		n_denominator = 0;
	}

	Fraction::Fraction(int a, int b)
	{
		bool valid = a >= 0 && b > 0;

		if (valid)
		{
			n_numerator = a;
			n_denominator = b;

			reduce();
		}
		else
		{
			*this = Fraction();
		}
	}

	int Fraction::max(void) const
	{
		return std::max(n_numerator, n_denominator);
	}

	int Fraction::min(void) const
	{
		return std::min(n_numerator, n_denominator);
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce(void)
	{
		int greatestCommonDivisor = gcd();

		n_numerator /= greatestCommonDivisor;
		n_denominator /= greatestCommonDivisor;
	}

	void Fraction::display(void) const
	{
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (n_denominator == 1)
		{
			cout << n_numerator;
		}
		else
		{
			cout << n_numerator << "/" << n_denominator;
		}
	}

	bool Fraction::isEmpty(void) const
	{
		// if Safe Empty State, return true
		return (n_numerator == 0 and n_denominator == 0);
	}

	bool Fraction::isNegative(int x) const
	{
		//returns 0 if x is negative
		return (x < 0);
	}

	bool Fraction::isValid(const Fraction& fraction) const
	{
		bool validFraction = fraction.n_numerator >= 0 && fraction.n_denominator > 0;
		return validFraction;
	}

	bool Fraction::fractionsAreEqual(const Fraction& a, const Fraction& b) const
	{
		bool numeratorsEqual = a.n_numerator == b.n_numerator;
		bool denominatorsEqual = a.n_denominator == b.n_denominator;
		return numeratorsEqual && denominatorsEqual;
	}

	bool Fraction::numeratorAndDenominatorAreEqual(void) const
	{
		return n_numerator == n_denominator;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		Fraction temp(1, -1);

		if (isEmpty() == false && rhs.isEmpty() == false)
		{
			temp.n_numerator = ((n_numerator*rhs.n_denominator) + (rhs.n_numerator*n_denominator));
			temp.n_denominator = (n_denominator*rhs.n_denominator);
		}
		return temp;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const
	{
		Fraction temp;
		bool valid = isValid(*this) && isValid(rhs);

		if (valid)
		{
			temp.n_numerator = this->n_numerator * rhs.n_numerator;
			temp.n_denominator = this->n_denominator * rhs.n_denominator;
			return temp;
		}
		else
		{
			temp = Fraction();
			return temp;
		}
	}

	bool Fraction::operator==(const Fraction& rhs) const
	{
		bool validFractions = isValid(*this) && isValid(rhs);
		bool equalFractions = fractionsAreEqual(*this, rhs) == false;
		return validFractions && equalFractions;
	}

	bool Fraction::operator!=(const Fraction& rhs) const
	{
		bool validFractions = isValid(*this) && isValid(rhs);
		bool inEqualFractions = fractionsAreEqual(*this, rhs) == false;
		return validFractions && inEqualFractions;
	}

	Fraction& Fraction::operator+=(const Fraction& rhs)
	{
		n_numerator = n_numerator * rhs.n_denominator + n_denominator * rhs.n_numerator;
		n_denominator = n_denominator * rhs.n_denominator;
		reduce();
		return *this;
	}

}