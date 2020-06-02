//**********************************************************************
// OOP244 Workshop 8 - Virtual Functions and Abstract Base Classes
// Version: 1.0
// 2018/11/13
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#ifndef SICT_IACCOUNT_H_
#define SICT_IACCOUNT_H_

#include <iostream>

namespace sict {

	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount();
	};
	iAccount* CreateAccount(const char*, double);
}

#endif