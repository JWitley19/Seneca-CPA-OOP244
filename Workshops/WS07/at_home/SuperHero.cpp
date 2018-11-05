/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#include <iostream>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict
{
	// set the object to a safe empty state by calling the Hero() and setting the bonus manually
	SuperHero::SuperHero() : Hero()
	{
		h_bonus = 0;
		h_defend = 0;
	}

	// checks if the parameters are valid and then calls parameter constructor from Hero
	// apply the bonus right at the begginning
	SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defend) : Hero(name, health, attack)
	{
		h_bonus = bonus;
		h_defend = defend;
	}

	// if the attack strength is in a safe empty state, return 0, else add the bonus
	int SuperHero::attackStrength() const
	{
		return Hero::attackStrength() != -1 ? Hero::attackStrength() + h_bonus : 0;
	}

	// same logic as the attack strength
	int SuperHero::defend() const
	{
		return (h_defend != -1) ? h_defend : 0;
	}

	// add the bonus to the attacks of the superheroes
	// call the operator from the other class
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero left = first;
		SuperHero right = second;
		SuperHero winner;

		int round = 0;

		for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); i++)
		{
			left -= right.attackStrength() - left.defend();
			right -= left.attackStrength() - right.defend();
			round = i;
		}

		round++;

		if (!left.isAlive() && !right.isAlive())
		{
			winner = left;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}
		else if (!left.isAlive())
		{
			winner = right;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return second;
		}
		else if(!right.isAlive())
		{
			winner = left;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}
		else
		{
			return first;
		}
	}
}