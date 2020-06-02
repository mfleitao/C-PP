//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#include <iostream>
#include "SavingsAccount.h"
using namespace sict;

namespace sict {

	iAccount* CreateAccount(const char* typeOfAccount, double blc) {
		if (typeOfAccount != nullptr && typeOfAccount[0] != '\0') {
			if (typeOfAccount[0] == 'S' || typeOfAccount[0] == 's') {
				iAccount* savings = new SavingsAccount(blc, 0.05);
				return savings;
			}
		}
		return nullptr;
	}

}