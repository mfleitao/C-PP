//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#ifndef SICT_SAVINGSACCOUNT_H_
#define SICT_SAVINGSACCOUNT_H_

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {
		double interestRate;
		
	public:
		SavingsAccount(double, double);
		~SavingsAccount();
		void monthEnd();
		void display(std::ostream&) const;
	};

}

#endif