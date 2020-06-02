// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#include <iostream>
#include <cstring>
#include <string>
#include "Perishable.h"
using namespace std;

namespace aid {

	Perishable::Perishable() : Good('P') { }

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Good::store(file, false);
		file << COMMA;
		file << expiry().getYear() << '/';
		file << expiry().getMonth() << '/';
		file << expiry().getDay();
		if (newLine) file << endl;
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file);
		string dateStr;
		getline(file, dateStr, '\n');
		if (file.fail()) {
			file.clear();
			file.close();
			return file;
		}

		char* year = new char[4]; // 4 is the number of year digits
		strcpy(year, dateStr.substr(0, 4).c_str());
		year[4] = '\0';
		int y = atoi(year);

		char* month = new char[2]; // 2 is the number of month digits
		strcpy(month, dateStr.substr(5, 2).c_str());
		month[2] = '\0';
		int m = atoi(month);

		char* day = new char[2]; // 2 is the number of day digits
		strcpy(day, dateStr.substr(8, 2).c_str());
		day[2] = '\0';
		int d = atoi(day);

		date = Date(y, m, d);
		file.clear();
		file.close();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Good::write(os, linear);
		if (!expiry().isEmpty() && isClear()) {
			if (!linear)
				os << endl << " Expiry date: ";

			os << expiry().getYear() << '/';
			os << expiry().getMonth() << '/';
			os << expiry().getDay();
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Good::read(is);
		cout << " Expiry date (YYYY/MM/DD): ";
		Date *tmpDate = new Date();
		tmpDate->read(is);
		if (is.fail()) {
			is.setstate(std::ios::failbit);
			return is;
		}

		if (tmpDate->bad()) {
			is.setstate(std::ios::failbit);
			switch (tmpDate->errCode()) {
				case CIN_FAILED	: Good::message("Invalid Date Entry"); break;
				case YEAR_ERROR	: Good::message("Invalid Year in Date Entry"); break;
				case MON_ERROR	: Good::message("Invalid Month in Date Entry"); break;
				case DAY_ERROR	: Good::message("Invalid Day in Date Entry"); break;
				case PAST_ERROR	: Good::message("Invalid Expiry in Date Entry"); break;
			}
			return is;
		}
		date = *tmpDate;
		return is;
	}

	const Date& Perishable::expiry() const {
		return date;
	}

}