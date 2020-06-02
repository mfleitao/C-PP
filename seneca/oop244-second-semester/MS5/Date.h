// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR 0		// No error - the date is valid
#define CIN_FAILED 1	// istream failed on information entry
#define DAY_ERROR 2		// Day value is invalid
#define MON_ERROR 3		// Month value is invalid
#define YEAR_ERROR 4	// Year value is invalid
#define PAST_ERROR 5	// Date value is invalid

#include <iostream>

namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date {

		int year;
		int month;
		int day;
		int errorState;
		int comparator;

		int mdays(int, int) const;
		bool validateDate(int y, int m, int d);
		int digits(int n);

	public:

		Date();
		Date(int y, int m, int d);

		bool isEmpty() const;
		int calcComparator(int y, int m, int d) const;
		void errCode(int errorCode);
		int errCode() const;
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		bool bad() const;
		Date& operator=(const Date& date);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};

	std::istream& operator>>(std::istream& is, Date& d);
	std::ostream& operator<<(std::ostream& os, const Date& d);

}
#endif