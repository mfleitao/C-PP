//**********************************************************************
// Workshop #4: Constructors
// Version: 1.0
// w4_in_lab.cpp
// 2018/10/02
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Passenger.h"
#include "Passenger.h" // this is intentional

using namespace std;
using namespace sict;

int main() {
	const int no_passengers = 8;
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger("Christopher Szwartenegger", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only passengers 5 and 6 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < no_passengers; ++i)
	{
		cout << "Passenger " << i + 1 << ": "
			<< (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	Passenger vanessa("Vanessa", "Paris"),
		mike("Mike", "Tokyo"),
		chris("Christopher Szwartzenneger", "Toronto"),
		alice("Alice", "Paris");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	chris.display();
	travellers[0].display();
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
