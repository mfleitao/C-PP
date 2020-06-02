//**********************************************************************
// Workshop #4: Constructors
// Version: 1.0
// Passenger.cpp
// 2018/10/02
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		this->name[0] = '\0';
		this->destination[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name != nullptr && name[0] != '\0' && destination != nullptr && destination[0] != '\0') {
			strncpy(this->name, name, max_length);
			strncpy(this->destination, destination, max_length);
			this->name[max_length] = NULL;
			this->destination[max_length] = NULL;
		} 
		else {
			this->name[0] = '\0';
			this->destination[0] = '\0';
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return (this->name[0] != '\0' && this->destination[0] != '\0') ? false : true;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (this->name[0] != '\0' && this->destination[0] != '\0')
			cout << this->name << " - " << this->destination << endl;
		else
			cout << "No passenger!" << endl;
	}

}
