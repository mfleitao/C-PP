//**********************************************************************
// Workshop #4: Constructors
// Version: 1.0
// Passenger.cpp
// 2018/10/04
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"
using namespace std;

namespace sict {

	Passenger::Passenger() {
		setSafeEmptyState();
	}

	Passenger::Passenger(const char* name, const char* destination) {
		if (name != nullptr && name[0] != '\0' && destination != nullptr && destination[0] != '\0') {
			strncpy(this->passengerName, name, max_length);
			strncpy(this->destination, destination, max_length);
			this->passengerName[max_length] = '\0';
			this->destination[max_length] = '\0';
			// sets the departure date to October 1st, 2018
			this->yearOfDeparture = 2018;
			this->monthOfDeparture = 10;
			this->dayOfDeparture = 1;
		}
		else {
			setSafeEmptyState();
		}
	}

	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
		if (name != nullptr && name[0] != '\0' 
			&& destination != nullptr && destination[0] != '\0'
			&& year >= 2018 && year <= 2020 
			&& month >= 1 && month <= 12 
			&& day >= 1 && day <= 31) {
			// set valid values
			strncpy(this->passengerName, name, max_length);
			strncpy(this->destination, destination, max_length);
			this->passengerName[max_length] = '\0';
			this->destination[max_length] = '\0';
			this->yearOfDeparture = year;
			this->monthOfDeparture = month;
			this->dayOfDeparture = day;
		}
		else {
			setSafeEmptyState();
		}
	}

	void Passenger::setSafeEmptyState() {
		this->passengerName[0] = '\0';
		this->destination[0] = '\0';
		this->yearOfDeparture = 0;
		this->monthOfDeparture = 0;
		this->dayOfDeparture = 0;
	}

	bool Passenger::isEmpty() const {
		return (this->passengerName[0] != '\0' && this->destination[0] != '\0') ? false : true;
	}

	void Passenger::display() const {
		if (this->passengerName[0] != '\0' && this->destination[0] != '\0') {
			cout << this->passengerName << " - " << this->destination << " on " << this->yearOfDeparture << "/";
			cout << setw(2) << setfill('0') << this->monthOfDeparture << "/";
			cout << setw(2) << setfill('0') << this->dayOfDeparture << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}

	const char* Passenger::name() const {
		return this->passengerName;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const {
		return (strcmp(passenger.destination, this->destination) == 0
			&& passenger.dayOfDeparture == this->dayOfDeparture
			&& passenger.monthOfDeparture == this->monthOfDeparture
			&& passenger.yearOfDeparture == this->yearOfDeparture) ? true : false;
	}
	
}
