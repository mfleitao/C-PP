/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 18/09/2018
// Author Matheus Leitao
// Description: in_lab
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {

	// prints the object to the screen in the following format:
	// KINGDOM_NAME, population POPULATION<ENDL>
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}
