/**********************************************************
// Workshop 3: Classes and Privacy
// Version 2.1
// 2018/09/25
// Matheus Fernando Leitão
// ID: 148 300 171
**********************************************************/
#include <iostream>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	bool CRA_Account::isEmpty() const {
		return (this->sin < sict::min_sin || this->sin > sict::max_sin) ? true : false;
	}

	void CRA_Account::display() const {
		if (sin < 0) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << familyName << endl;
			cout << "Given Name : " << givenName << endl;
			cout << "CRA Account: " << sin << endl;
		}
	}

}