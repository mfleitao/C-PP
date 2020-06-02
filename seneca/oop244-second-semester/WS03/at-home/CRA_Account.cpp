/**********************************************************
// Workshop 3: Classes and Privacy
// Version 2.1
// 2018/09/25
// Matheus Fernando Leitão
// ID: 148 300 171
// Description: at_home
**********************************************************/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (familyName != nullptr && familyName[0] != '\0' && givenName != nullptr && givenName[0] != '\0' && sin > 0) {
			if (isSINvalid(sin)) {
				strcpy(this->familyName, familyName);
				strcpy(this->givenName, givenName);
				for (int i = 0; i < sict::max_yrs; i++)
					this->year[i] = 0;
				this->balance[sict::max_yrs] = { 0.0 };
				this->sin = sin;
			}
		}
	}

	void CRA_Account::set(int year, double balance) {
		for (int i = 0; i < sict::max_yrs; i++) {
			if (this->year[i] == 0) {
				this->year[i] = year;
				this->balance[i] = balance;
				i = sict::max_yrs;
			}
		}
	}

	bool CRA_Account::isEmpty() const {
		return (this->sin < sict::min_sin || this->sin > sict::max_sin) ? true : false;
	}

	void CRA_Account::display() const {
		if (this->sin < 0) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << this->familyName << endl;
			cout << "Given Name : " << this->givenName << endl;
			cout << "CRA Account: " << this->sin << endl;

			for (int i = 0; i < sict::max_yrs; i++) {
				if (this->balance[i] > 2.0) {
					cout << "Year (" << this->year[i] << ") balance owing: ";
					cout << fixed << setprecision(2) << fabs(this->balance[i]) << endl;
				}
				else if (this->balance[i] < -2.0) {
					cout << "Year (" << this->year[i] << ") refund due: ";
					cout << fixed << setprecision(2) << fabs(this->balance[i]) << endl;
				}
				else {
					cout << "Year (" << this->year[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
	}

	bool CRA_Account::isSINvalid(int sin) const {
		int sinArray[sict::sin_size] = { 0 };
		int firstSum = 0, secondSum = 0, totalSum = 0, i, j;

		for (i = sict::sin_size - 1; i >= 0; i--) {
			sinArray[i] = sin % 10;
			sin /= 10;
		}

		for (j = 0; j < sict::sin_size; j++) {
			if (j == 1 || j == 3 || j == 5 || j == 7) {
				int current = sinArray[j] + sinArray[j];
				firstSum += current % 10;
				current /= 10;
				firstSum += current % 10;
			}
			else if (j == 0 || j == 2 || j == 4 || j == 6) {
				secondSum += sinArray[j];
			}
		}
		totalSum = firstSum + secondSum;
		return (sinArray[sin_size - 1] == (10 - (totalSum % 10))) ? true : false;
	}

}