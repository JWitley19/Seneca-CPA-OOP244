/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 04/11/2018
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"

using namespace std;

namespace sict
{
	Hero::Hero()
	{
		h_name[0] = '\0';
		h_health = 0;
		h_attack = 0;
	}

	Hero::Hero(const char* p_name, int p_health, int p_attack)
	{
		bool s_name = p_name != nullptr && p_name[0] != '\0';
		bool s_health = p_health > 0;
		bool s_attack = p_attack > 0;

		if (s_name && s_health && s_attack)
		{
			strcpy(h_name, p_name);
			h_health = p_health;
			h_attack = p_attack;
		}
		else
		{
			*this = Hero();
		}
	}

	// receives an attack strength
	// if p_attack > 0
	// h_health -= p_attack
	// else, do nothing
	// if h_attack is 0 0r -, set h_health to 0
	void Hero::operator-=(int p_attack)
	{
		if (p_attack > 0 && h_health > 0)
		{
			h_health -= p_attack;

			if (h_health < 0)
			{
				h_health = 0;
			}
		}
	}

	// returns true if the object is health
	bool Hero::isAlive() const
	{
		return (h_health > 0) ? true : false;
	}

	// returns the attack strength of the current object
	int Hero::attackStrength()const
	{
		if (h_attack > 0)
			return h_attack;
		else
			return 0;
	}

	const char* Hero::getName() const
	{
		return h_name;
	}

	int Hero::getHealth() const
	{
		return h_health;
	}

	// inserts the hero.h_name into os
	// returns a reference to the stream
	// if hero.h_name[0] = '\0'
	// display "No hero"
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.h_name[0] != '\n' && hero.h_health != -1 && hero.h_attack != -1)
			os << hero.h_name;
		else
			os << "No hero";
		return os;
	}

	// returns a reference to the winner of the battle between the heroes
	// displays the names of the battle participants
	// makes local copies of the participants
	// determines the damage that each inflicts on the other in a single attack
	// battle until one of them dies
	// display the name of the winner
	// if ther's a draw, the first is the winner
	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero left = first, right = second, winner;
		int round = 0;

		for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
		{
			left -= right.attackStrength();
			right -= left.attackStrength();
			round = i;
		}

		round++;

		if (!left.isAlive() && !right.isAlive())
		{
			winner = left;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}
		else if (!left.isAlive())
		{
			winner = right;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return second;
		}
		else if (!right.isAlive())
		{
			winner = left;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}

		else
		{
			return first;
		}
	}
}