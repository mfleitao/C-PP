//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#include <iostream>
#include <iomanip>
#include <math.h>
#include "SavingsAccount.h"
using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double blc, double rate) : Account(blc) {
		interestRate = (rate > 0.0) ? rate : 0.0;
	}

	void SavingsAccount::monthEnd() {
		double calc = getBalance() * interestRate;
		credit(calc);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl;
		os << "Balance: $" << fixed << setprecision(2) << fabs(getBalance()) << endl;
		os << "Interest Rate (%): " << fixed << setprecision(2) << fabs(interestRate * 100) << endl;
	}

	SavingsAccount::~SavingsAccount() {

	}

}