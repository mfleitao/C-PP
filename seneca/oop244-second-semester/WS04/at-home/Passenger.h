//**********************************************************************
// Workshop #4: Constructors
// Version: 1.0
// Passenger.h
// 2018/10/04
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_

namespace sict {

	const int max_length = 18;

	class Passenger {

	private:
		char passengerName[max_length + 1];
		char destination[max_length + 1];
		int yearOfDeparture;
		int monthOfDeparture;
		int dayOfDeparture;
		void setSafeEmptyState();

	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;

	};

}

#endif 
