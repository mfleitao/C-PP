//**********************************************************************
// Workshop 5: Operator Overloading
// Version: 1.0
// Fraction.cpp
// 2018/10/09
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {

	Fraction::Fraction() {
		setSafeEmptyState();
	}

	Fraction::Fraction(int numerator, int denominator) {
		if (numerator > 0 && denominator > 0) {
			this->numerator = numerator;
			this->denominator = denominator;
			this->reduce();
		}
		else {
			setSafeEmptyState();
		}
	}

	void Fraction::setSafeEmptyState() {
		this->numerator = 0;
		this->denominator = 0;
	}

	int Fraction::max() const {
		return (this->numerator > this->denominator) ? this->numerator : this->denominator;
	}

	int Fraction::min() const {
		return (this->numerator < this->denominator) ? this->numerator : this->denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int gcd = this->gcd();
		this->numerator = this->numerator / gcd;
		this->denominator = this->denominator / gcd;
	}

	void Fraction::display() const {
		if (this->denominator != 1 && this->denominator > 0)
			cout << this->numerator << "/" << this->denominator;
		else if (this->denominator == 1)
			cout << this->numerator;
		else
			cout << "no fraction stored";
	}

	bool Fraction::isEmpty() const {
		return (this->numerator == 0 && this->denominator == 0) ? true : false;
	}

	bool Fraction::isEquals(const Fraction& rhs) const {
		return (this->numerator == rhs.numerator && this->denominator == rhs.denominator) ? true : false;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		return (isEmpty() || rhs.isEmpty()) ? false : this->isEquals(rhs);
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		return (isEmpty() || rhs.isEmpty()) ? false : !this->isEquals(rhs);
	}

	// 'A' equals Addition, 'M' equals Multiplication
	// --------------------------------------------------------------------------
	Fraction Fraction::sub(const Fraction& rhs, char type) const {
		int ad = this->numerator * rhs.denominator;
		int bc = this->denominator * rhs.numerator;
		int bd = this->denominator * rhs.denominator;
		int adbc = (type == 'A') ? ad + bc : ad * bc; 
		Fraction copy(adbc, bd);
		copy.reduce();
		return copy;
	}

	Fraction Fraction::operator+(const Fraction& rhs) const {
		return (isEmpty() || rhs.isEmpty()) ? Fraction() : this->sub(rhs, 'A'); // Addition
	}

	Fraction Fraction::operator*(const Fraction& rhs) const {
		return (isEmpty() || rhs.isEmpty()) ? Fraction() : this->sub(rhs, 'M'); // Multiplication
	}

	// Modifier Method to add a Fraction to the current object
	Fraction Fraction::operator+=(const Fraction& rhs) {
		if (isEmpty() || rhs.isEmpty()) {
			return Fraction();
		}
		else {
			int ad = this->numerator * rhs.denominator;
			int bc = this->denominator * rhs.numerator;
			int bd = this->denominator * rhs.denominator;
			this->numerator = ad + bc;
			this->denominator = bd;
			this->reduce();
			return *this;
		}
	}

}
