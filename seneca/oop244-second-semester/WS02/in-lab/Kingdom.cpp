/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 2.0
// Date 22/09/2018
// Author Matheus Leitao
// Description: at_home
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {

	// prints the object to the screen in the following format:
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

	void display(const Kingdom kingdom[], int numOfElements) {
		
		int totalOfPopulation = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		
		for (int i = 0; i < numOfElements; i++) {
			cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
			totalOfPopulation += kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalOfPopulation << endl;
		cout << "------------------------------" << endl;
	}

}
