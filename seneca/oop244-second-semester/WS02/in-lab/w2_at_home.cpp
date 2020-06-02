/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
// Date 22/09/2018
// Author Matheus Leitao
// Description: at_home
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	Kingdom* pKingdom = { 0 };

	cout << "==========\n";
	cout << "Input data\n";
	cout << "==========\n";
	cout << "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}

	cout << "==========" << endl << endl;
	// testing that "display(...)" works
	cout << "------------------------------" << endl;
	cout << "The 1st Kingdom entered is" << endl;
	cout << "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element
	// TODO: allocate dynamic memory for count + 1 Kingdoms
	Kingdom* newKingdom = new Kingdom[count + 1];

	// TODO: copy elements from original array into this newly allocated array
	for (int i = 0; i < count; i++) {
		newKingdom[i] = pKingdom[i];
	}
	
	// TODO: copy the address of the newly allocated array into pKingdom pointer
	pKingdom = newKingdom;

	// add the new Kingdom
	cout << "==========\n";
	cout << "Input data\n";
	cout << "==========\n";
	cout << "Kingdom #" << count + 1 << ": " << endl;
	// TODO: accept input for the new element in the array
	read(pKingdom[count]);
	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	sict::display(pKingdom, count);
	cout << endl;

	// TODO: deallocate the dynamic memory for the original array
	delete[] pKingdom;
	pKingdom = nullptr;

	return 0;
}

// read accepts data for a Kingdom from standard input
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
