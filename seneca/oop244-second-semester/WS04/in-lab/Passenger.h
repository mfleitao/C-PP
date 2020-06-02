//**********************************************************************
// Workshop #4: Constructors
// Version: 1.0
// Passenger.h
// 2018/10/02
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#define _CRT_SECURE_NO_WARNINGS

#ifndef SICT_PASSENGER_H_
#define SICT_PASSENGER_H_

namespace sict {

	const int max_length = 18;

	class Passenger {

	private:
		char name[max_length + 1];
		char destination[max_length + 1];

	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;

	};

}

#endif 
