// ***********************************************************
// Assembly Line Project
// Utilities.cpp
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;

namespace sict {

	char Utilities::delimiter = { '\0' };
	size_t Utilities::fieldWidth = { 1 };

	Utilities::Utilities() { }

	const string Utilities::extractToken(const string& str, size_t& nextPosition) {
		string aux = str.substr(nextPosition);
		string token = "";
		size_t pos = 0;
		bool lastField = false;

		if (aux.find(delimiter) < aux.find("\n"))
			token = aux.substr(0, aux.find(delimiter));
		else {
			token = aux.substr(0, aux.npos);
			lastField = true;
		}
		pos = nextPosition + token.length() + 1;
		if (lastField)
			pos--;
		else {
			if ((pos - nextPosition - 1) > getFieldWidth())
				setFieldWidth(pos - nextPosition - 1);
			if (str.substr(pos, 1) == string(1, delimiter))
				throw "Error - There are two delimiters which are in sequence";
		}

		nextPosition = pos;
		return token;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}

	size_t Utilities::getFieldWidth() {
		return fieldWidth;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t w) {
		fieldWidth = w;
	}

};