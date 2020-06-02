//**********************************************************************
// Workshop 5: Operator Overloading
// Version: 1.0
// Fraction.h
// 2018/10/09
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************
#ifndef SICT_FRACTION_H_
#define SICT_FRACTION_H_

namespace sict {

	class Fraction {

	private:
		int numerator;
		int denominator;

		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		void setSafeEmptyState();
		bool isEquals(const Fraction&) const;
		Fraction sub(const Fraction& rhs, char) const;

	public:
		Fraction();
		Fraction(int, int);

		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);

	};

}

#endif
