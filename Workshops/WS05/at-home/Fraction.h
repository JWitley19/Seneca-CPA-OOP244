/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 11/10/2018
 **********************************************************/

#ifndef Sict_Fraction_H_
#define Sict_Fraction_H_


namespace sict
{
	class Fraction {

	private:
		int n_numerator;
		int n_denominator;

	public:
		Fraction(void);
		Fraction(int a, int b);
		int max(void) const;
		int min(void) const;
		void reduce(void);
		int gcd(void) const;
		bool isEmpty(void) const;
		bool isNegative(int x) const;
		void display(void) const;
		bool numeratorAndDenominatorAreEqual(void) const;
		bool isValid(const Fraction& fraction) const;
		bool fractionsAreEqual(const Fraction& a, const Fraction& b) const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
	};
}

#endif // !Sict_Fraction_H_


