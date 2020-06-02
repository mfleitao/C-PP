//**********************************************************************
// OOP244 Workshop 7 - Derived Classes
// Version: 1.0
// 2018/11/10
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {

	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attackStrength = 0;
	}

	Hero::Hero(const char* n, const int h, const int ats) {
		if (n != nullptr && n[0] != '\0' && h > 0 && ats > 0) {
			strncpy(name, n, MAX_NAME_LEN);
			name[MAX_NAME_LEN] = '\0';
			health = h;
			attackStrength = ats;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
			if (health < 0)
				health = 0;
		}
	}

	bool Hero::isAlive() const {
		return (health > 0);
	}

	bool Hero::isEmpty() const {
		return (name[0] == '\0' && health == 0 && attackStrength == 0);
	}

	int Hero::getAttackStrength() const {
		if (!isEmpty())
			return attackStrength;
		return 0;
	}

	std::ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.name != nullptr && hero.name[0] != '\0')
			os << hero.name;
		else
			os << "No hero";
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero hero1 = first;
		Hero hero2 = second;
		int round = 0;
		int winner = 0;
		cout << "Ancient Battle! " << first << " vs " << second;
		for (int i = 0; i < MAX_ROUNDS; i++) {
			hero1 -= hero2.getAttackStrength();
			hero2 -= hero1.getAttackStrength();
			if (!hero1.isAlive()) {
				winner = 2;
				round = i + 1;
				i = MAX_ROUNDS;
			}
			else if (!hero2.isAlive()) {
				winner = 1;
				round = i + 1;
				i = MAX_ROUNDS;
			}
		}
		if (winner == 1) {
			cout << " : Winner is " << first << " in " << round << " rounds." << endl;
			return first;
		}
		else {
			cout << " : Winner is " << second << " in " << round << " rounds." << endl;
			return second;
		}
	}

}