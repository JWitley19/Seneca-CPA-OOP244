/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_
#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
	private:
		int h_bonus;
		int h_defend;
	public:
		// set SuperHero object to a safe empty state
		SuperHero();

		// check to see if the parameters have valid values
		// if not, set the object to a safe empty state
		SuperHero(const char* name, int health, int attack, int bonus, int defend);

		// Query: returns the attack strength of the current object including its super power bous
		// if the object is in an empty state, the function returns 0
		int attackStrength() const;

		// Query: returns the defend strength of the current object
		// if the object is in a safe empty state, the funcction returns 0
		int defend() const;
	};
	// NON FRIEND: returns a reference to the winner of the battle after max_rounds rounds 
	// the function displays the names of the battle participants as shown in the sample output
	// the function also makes local copies of the particiants
	// determines the damage that each participant inflicts on the other in a single attack
	// battles until either one of the participants dies or the maximum number of rounds
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H_