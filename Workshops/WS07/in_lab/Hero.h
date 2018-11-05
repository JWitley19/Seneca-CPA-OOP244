/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#ifndef SICT_HERO_H_
#define SICT_HERO_H_

namespace sict
{
	const int max_rounds = 100;

	class Hero
	{
	private:
		char h_name[41];
		int h_health;
		int h_attack;
	public:
		Hero();
		Hero(const char* p_name, int p_health, int p_attack);
		void operator -=(int p_attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* getName() const;
		int getHealth() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H_