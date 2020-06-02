// -----------------------------------------------------------
// Final Project Milestone 1
// Version 1.0
// Date: 02/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 1
// -----------------------------------------------------------
#include <iostream>
#include "Date.h"
using namespace std;

namespace aid {

	Date::Date() {
		year = 0;
		month = 0;
		day = 0;
		comparator = 0;
		errCode(NO_ERROR);
	}

	Date::Date(int y, int m, int d) {
		if (validateDate(y, m, d)) {
			year = y;
			month = m;
			day = d;
			errCode(NO_ERROR);
		}
		else {
			*this = Date();
		}
	}

	void Date::errCode(int errCode) {
		errorState = errCode;
	}

	int Date::errCode() const {
		return errorState;
	}

	bool Date::bad() const {
		return errCode() != NO_ERROR;
	}

	// number of days in month mon and year year
	int Date::mdays(int mon, int year) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	int Date::calcComparator(int y, int m, int d) const {
		return y * 372 + m * 31 + d;
	}

	bool Date::isEmpty() const {
		return (year == 0 && month == 0 && day == 0);
	}


	bool Date::operator==(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) == calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::operator!=(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) != calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::operator<(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) < calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::operator>(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) > calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::operator<=(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) <= calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::operator>=(const Date& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty()))
			return (calcComparator(year, month, day) >= calcComparator(rhs.year, rhs.month, rhs.day));
		return false;
	}

	bool Date::validateDate(int y, int m, int d) {
		if (y >= min_year && y <= max_year && digits(y) == 4) {
			if (m >= 1 && m <= 12 && (digits(m) == 2 || digits(m) == 1)) {
				if (d >= 1 && d <= mdays(m, y) && (digits(d) == 2 || digits(d) == 1)) {
					comparator = calcComparator(y, m, d);
					if (comparator >= min_date) {
						return true;
					}
					else {
						errCode(PAST_ERROR);
					}
				}
				else {
					errCode(DAY_ERROR);
				}
			}
			else {
				errCode(MON_ERROR);
			}
		}
		else {
			errCode(YEAR_ERROR);
		}
		return false;
	}

	int Date::digits(int n) {
		int digits = 0;
		if (n < 0)
			return 1;
		while (n) {
			n /= 10;
			digits++;
		}
		return digits;
	}

	std::istream& Date::read(std::istream& istr) {
		int y;
		int m;
		int d;
		char divisor;
		istr >> y >> divisor >> m >> divisor >> d;
		if (istr.fail()) {
			errCode(CIN_FAILED);
		} 
		else {
			if (validateDate(y, m, d)) {
				year = y;
				month = m;
				day = d;
				errCode(NO_ERROR);
			}
		}
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << month << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << day;
		return ostr;
	}

	std::istream& operator>>(std::istream& is, Date& d) {
		d.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Date& d) {
		d.write(os);
		return os;
	}

}
