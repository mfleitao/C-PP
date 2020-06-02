//**********************************************************************
// OOP244 Workshop 7 - Derived Classes
// Version: 1.0
// 2018/11/10
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_

#include <iostream>
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int bonus;
		int defendStrength;

	public:
		SuperHero();
		SuperHero(const char*, const int, const int, const int, const int);
		int defend() const;
		int getAttackStrength() const;

	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}

#endif