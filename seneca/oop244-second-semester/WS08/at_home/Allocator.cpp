//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	const double DEFAULT_INTEREST_RATE = 0.05;
	const double DEFAULT_TRANSACTION_FEE = 0.50;
	const double DEFAULT_MONTHLY_FEE = 2.00;

	iAccount* CreateAccount(const char* typeOfAccount, double blc) {
		iAccount* account = nullptr;
		if (typeOfAccount != nullptr && typeOfAccount[0] != '\0') {
			if (typeOfAccount[0] == 'S' || typeOfAccount[0] == 's') {
				account = new SavingsAccount(blc, DEFAULT_INTEREST_RATE);
			}
			else if (typeOfAccount[0] == 'C' || typeOfAccount[0] == 'c') {
				account = new ChequingAccount(blc, DEFAULT_TRANSACTION_FEE, DEFAULT_MONTHLY_FEE);
			}
		}
		return account;
	}

}