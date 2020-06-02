//**********************************************************************
// Workshop 5: Operator Overloading
// Version: 1.0
// Fraction.h
// 2018/10/09
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
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

	public:
		Fraction();
		Fraction(int, int);

		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const;

	};

}

#endif
