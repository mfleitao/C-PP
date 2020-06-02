//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include <iomanip>
#include <math.h>
#include "ChequingAccount.h"
using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double blc, double tranfee, double monFee) : Account(blc) {
		transactionFee = (tranfee > 0.0) ? tranfee : 0.0;
		monthEndFee = (monFee > 0.0) ? monFee : 0.0;
	}

	bool ChequingAccount::credit(double amount) {
		if (Account::credit(amount)) 
			return Account::debit(transactionFee);
		return false;
	}

	bool ChequingAccount::debit(double amount) {
		if (Account::debit(amount))
			return Account::debit(transactionFee);
		return false;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(monthEndFee);
	}

	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << fixed << setprecision(2) << fabs(getBalance()) << endl;
		os << "Per Transaction Fee: " << fixed << setprecision(2) << fabs(transactionFee) << endl;
		os << "Monthly Fee: " << fixed << setprecision(2) << fabs(monthEndFee) << endl;
	}

	ChequingAccount::~ChequingAccount() {

	}

}