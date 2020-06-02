/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 2.0
// Date 22/09/2018
// Author Matheus Leitao	
// Description: at_home
***********************************************************/

#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_

#define NAME_MAX 32

namespace sict {
	
	struct Kingdom {
		char m_name[NAME_MAX];
		int m_population;
	};

	// prints the object to the screen in the following format:
	void display(const Kingdom&);

	void display(const Kingdom[], int);
}

#endif