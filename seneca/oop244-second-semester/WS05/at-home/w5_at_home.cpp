//**********************************************************************
// Workshop 5: Operator Overloading
// Version: 1.0
// w5_at_home.cpp
// 2018/10/09
// Matheus Fernando Leitao
// ID: 148300171
// Description: at_home
//**********************************************************************

#include <iostream>
#include "Fraction.h"
using namespace sict;
using namespace std;


int main() {
	cout << "------------------------------" << endl;
    cout << "Fraction Class Test:" << endl;
    cout << "------------------------------" << endl;

    sict::Fraction a;
    cout << "Fraction a; // ";
    cout << "a = ";
    a.display();
    cout << endl;

    Fraction b(1, 3);
    cout << "Fraction b(1, 3); // ";
    cout << "b = ";
    b.display();
    cout << endl;

    Fraction c(-5, 15);
    cout << "Fraction c(-5, 15); //";
    cout << " c = ";
    c.display();
    cout << endl;

    Fraction d(2, 4);
    cout << "Fraction d(2, 4); //";
    cout << " d = ";
    d.display();
    cout << endl;

    Fraction e(8, 4);
    cout << "Fraction e(8, 4); //";
    cout << " e = ";
    e.display();
    cout << endl;

    cout << "a + b equals ";
    (a + b).display();
    cout << endl;

    cout << "b + d equals ";
    (b + d).display();
    cout << endl;

    cout << "(b += d) equals ";
    (b += d).display();
    cout << endl;

    cout << "b equals ";
    b.display();
    cout << endl;

    cout << "(a == c) equals ";
    cout << ((a == c) ? "true" : "false");
    cout << endl;

    cout << "(a != c) equals ";
    cout << ((a != c) ? "true" : "false");
    cout << endl;
   
    return 0;
}
