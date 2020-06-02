//**********************************************************************
// Workshop 6: Class with a Resource
// Version: 1.0
// 2018/11/01
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_

namespace sict {

	const int MAX_CHAR = 20;

	class Contact {

		char name[MAX_CHAR + 1];
		int numPhones;
		long long* phoneNumbers;

		int countryCode(long long ph) const;
		int areaCode(long long ph) const;
		int firstDigitsNumber(long long ph) const;
		int lastDigitsNumber(long long ph) const;
		int getAreaCodeFirstDigit(long long ph) const;
		int getFirstDigitNumber(long long ph) const;
		int digits(long long n) const;
		bool validatePhoneNumber(long long phone) const;

	public:

		Contact();
		Contact(const char* name, const long long* phones, int numPhones);
		~Contact();

		bool isEmpty() const;
		void display() const;
	};

}

#endif 