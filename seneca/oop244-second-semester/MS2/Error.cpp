// -----------------------------------------------------------
// Final Project Milestone 2
// Version 1.0
// Date: 06/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 2
// -----------------------------------------------------------
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid {

	Error::Error(const char* msg) {
		messageError = nullptr;
		if (msg != nullptr) {
			messageLength = strlen(msg);
			messageError = new char[messageLength + 1];
			strncpy(messageError, msg, messageLength);
			messageError[messageLength] = '\0';
		}
	}

	Error::~Error() {
		delete[] messageError;
		messageError = nullptr;
	}

	void Error::clear() {
		delete[] messageError;
		messageError = nullptr;
	}

	bool Error::isClear() const {
		if (messageError != nullptr) {
			for (int i = 0; i < messageLength; i++) {
				if (messageError[i] != '\0')
					return false;
			}
		}
		return true;
	}

	void Error::message(const char* str) {
		delete[] messageError;
		messageLength = strlen(str);
		messageError = nullptr;
		messageError = new char[messageLength + 1];
		strncpy(messageError, str, messageLength);
		messageError[messageLength] = '\0';
	}

	const char* Error::message() const {
		return messageError;
	}

	std::ostream& operator<<(std::ostream& os, const Error& er) {
		if (!er.isClear())
			os << er.message();
		return os;
	}

}