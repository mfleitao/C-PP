
#ifndef SICT_HERO_H_
#define SICT_HERO_H_

#include <iostream>

namespace sict {

	const int MAX_ROUNDS = 100;
	const int MAX_NAME_LEN = 40;

	class Hero {
		
		char name[MAX_NAME_LEN + 1];
		int health;
		int attackStrength;

	public:
		Hero();
		Hero(const char* name, const int health, const int attackStrength);
		void operator-=(int attack);
		bool isAlive() const;
		int getAttackStrength() const;
		bool isEmpty() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
		
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif