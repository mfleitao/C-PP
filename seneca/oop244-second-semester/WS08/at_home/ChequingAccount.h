//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#ifndef SICT_CHEQUINGACCOUNT_H_
#define SICT_CHEQUINGACCOUNT_H_

#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		double transactionFee;
		double monthEndFee;

	public:
		ChequingAccount(double, double, double);
		~ChequingAccount();
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

}

#endif