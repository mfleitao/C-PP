//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include "Account.h"

namespace sict {

	Account::Account(double blc) {
		balance = (blc < 0.0) ? 0.0 : blc;
	}

	double Account::getBalance() const {
		return balance;
	}

	bool Account::credit(double amount) {
		bool credit = false;
		if (amount > 0.0) {
			balance += amount;
			credit = true;
		}
		return credit;
	}

	bool Account::debit(double amount) {
		bool debit = false;
		if (amount > 0.0) {
			balance -= amount;
			debit = true;
		}
		return debit;
	}

	Account::~Account() {

	}

	iAccount::~iAccount() {

	}

}