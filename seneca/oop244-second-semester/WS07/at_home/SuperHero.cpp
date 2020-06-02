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
#include "SuperHero.h"
using namespace std;

namespace sict {

	SuperHero::SuperHero() {
		bonus = 0;
		defendStrength = 0;
	}

	SuperHero::SuperHero(const char* name, const int helth, const int attck, const int bn, const int def) 
		: Hero(name, helth, attck) {
		if (bn > 0 && def > 0) {
			bonus = bn;
			defendStrength = def;
		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::defend() const {
		return (defendStrength > 0) ? defendStrength : 0;
	}

	int SuperHero::getAttackStrength() const {
		return (bonus > 0 && Hero::getAttackStrength() > 0) ? Hero::getAttackStrength() + bonus : 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero spHero1 = first;
		SuperHero spHero2 = second;
		int round = 0;
		int winner = 0;
		cout << "Super Fight! " << first << " vs " << second;
		for (int i = 0; i < MAX_ROUNDS; i++) {
			spHero1 -= spHero2.getAttackStrength() - spHero1.defend();
			spHero2 -= spHero1.getAttackStrength() - spHero2.defend();
			if (!spHero1.isAlive()) {
				winner = 2;
				round = i + 1;
				i = MAX_ROUNDS;
			}
			else if (!spHero2.isAlive()) {
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