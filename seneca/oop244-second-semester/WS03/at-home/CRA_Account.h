/**********************************************************
// Workshop 3: Classes and Privacy
// Version 2.1
// 2018/09/25
// Matheus Fernando Leitão
// ID: 148 300 171
// Description: at_home
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H_
#define SICT_CRA_ACCOUNT_H_

namespace sict {

	const int max_name_length = 40;

	const int min_sin = 100000000;

	const int max_sin = 999999999;

	const int max_yrs = 4;

	const int sin_size = 9;

	class CRA_Account {

	private:

		int sin;

		char familyName[max_name_length + 1];

		char givenName[max_name_length + 1];

		double balance[max_yrs];

		int year[max_yrs];

		bool isSINvalid(int) const;

	public:

		void set(const char*, const char*, int);

		void set(int , double);

		bool isEmpty() const;

		void display() const;

	};

}

#endif
