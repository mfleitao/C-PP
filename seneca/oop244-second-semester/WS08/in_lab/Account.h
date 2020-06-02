//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#ifndef SICT_ACCOUNT_H_
#define SICT_ACCOUNT_H_

#include <iostream>
#include "iAccount.h"

namespace sict {

	class Account : public iAccount {
		double balance;

	public:
		Account(double);
		~Account();
		bool credit(double);
		bool debit(double);
	protected: double getBalance() const;
	};

}

#endif