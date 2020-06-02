// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid {

	Error::Error(char* msg = nullptr) {
		messageError = msg;
		if (msg != nullptr && strlen(msg) > 0) {
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
		return (messageError == nullptr);
	}

	void Error::message(const char* str) {
		if (str != nullptr && strlen(str) > 0) {
			messageLength = strlen(str);
			messageError = nullptr;
			messageError = new char[messageLength + 1];
			strncpy(messageError, str, messageLength);
			messageError[messageLength] = '\0';
		}
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