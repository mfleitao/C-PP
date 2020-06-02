//**********************************************************************
// Workshop 6: Class with a Resource
// Version: 1.0
// 2018/11/01
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		numPhones = 0;
		phoneNumbers = nullptr;
	}

	Contact::Contact(const char* n, const long long* ph, int num) {
		if (n != nullptr && n != '\0') {
			strncpy(name, n, MAX_CHAR);
			name[MAX_CHAR] = '\0';
			phoneNumbers = nullptr;
			numPhones = 0;
			if (ph != nullptr && num > 0) {
				int numValidPhones = 0;
				for (int i = 0; i < num; i++) {
					if (validatePhoneNumber(ph[i]))
						numValidPhones++;
				}
				numPhones = numValidPhones;
				phoneNumbers = new long long[numPhones];
				int count = 0;
				while (count < numPhones) {
					for (int j = 0; j < num; j++) {
						if (validatePhoneNumber(ph[j])) {
							phoneNumbers[count] = ph[j];
							count++;
						}
					}
				}
			}
		}
		else {
			*this = Contact();
		}
	}

	Contact::Contact(const Contact& ct) {
		strncpy(name, ct.name, MAX_CHAR);
		numPhones = ct.numPhones;
		if (ct.phoneNumbers != nullptr) {
			phoneNumbers = new long long[numPhones];
			for (int i = 0; i < numPhones; i++)
				phoneNumbers[i] = ct.phoneNumbers[i];
		}
		else {
			phoneNumbers = nullptr;
		}
	}

	Contact& Contact::operator=(const Contact& ct) {
		if (this != &ct) {
			strncpy(name, ct.name, MAX_CHAR);
			numPhones = ct.numPhones;
			delete[] phoneNumbers;
			if (phoneNumbers != nullptr) {
				phoneNumbers = new long long[numPhones];
				for (int i = 0; i < numPhones; i++)
					phoneNumbers[i] = ct.phoneNumbers[i];
			}
			else {
				phoneNumbers = nullptr;
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long phone) {
		if (validatePhoneNumber(phone)) {
			if (phoneNumbers == nullptr) {
				numPhones = 1;
				phoneNumbers = new long long[numPhones];
				phoneNumbers[0] = phone;
			}
			else {
				long long* newPhoneList = new long long[numPhones + 1];
				for (int i = 0; i < numPhones; i++)
					newPhoneList[i] = phoneNumbers[i];
				newPhoneList[numPhones] = phone;
				numPhones++;
				delete[] phoneNumbers;
				phoneNumbers = nullptr;
				phoneNumbers = new long long[numPhones];
				for (int j = 0; j < numPhones; j++)
					phoneNumbers[j] = newPhoneList[j];
				delete[] newPhoneList;
				newPhoneList = nullptr;
			}
		}
		return *this;
	}

	int Contact::countryCode(long long phone) const {
		return phone / 10000000000LL;
	}

	int Contact::areaCode(long long phone) const {
		return (phone % 10000000000LL) / 10000000LL;
	}

	int Contact::firstDigitsNumber(long long phone) const {
		return (phone % 10000000LL) / 10000LL;
	}

	int Contact::lastDigitsNumber(long long phone) const {
		return phone % 10000LL;
	}

	int Contact::getAreaCodeFirstDigit(long long phone) const {
		return (phone % 10000000000LL) / 1000000000LL;
	}

	int Contact::getFirstDigitNumber(long long phone) const {
		return (phone % 10000000LL) / 1000000LL;
	}

	Contact::~Contact() {
		delete[] phoneNumbers;
		phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const {
		return (name == nullptr || name[0] == '\0');
	}

	void Contact::display() const {
		if (this->isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			if (numPhones > 0) {
				for (int i = 0; i < numPhones; i++) {
					cout << "(+" << countryCode(phoneNumbers[i]) << ") ";
					cout << areaCode(phoneNumbers[i]) << " ";
					cout << firstDigitsNumber(phoneNumbers[i]) << "-";
					cout.width(4);
					cout.fill('0');
					cout << lastDigitsNumber(phoneNumbers[i]) << endl;
				}
			}
		}
	}

	bool Contact::validatePhoneNumber(long long phone) const {
		if (digits(phone) == 12 || digits(phone) == 11) {
			if (countryCode(phone) > 0 && getAreaCodeFirstDigit(phone) > 0 && getFirstDigitNumber(phone) > 0)
				return true;
		}
		return false;
	}

	int Contact::digits(long long phoneNumber) const {
		int out = 0;
		if (phoneNumber < 0) return 1;
		while (phoneNumber) {
			phoneNumber /= 10;
			out++;
		}
		return out;
	}

}