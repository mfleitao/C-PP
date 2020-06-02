#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define COMMA ','

int main() {

	double d = 1.50;
	cout << fixed << setprecision(2) << d;

	cout << endl << endl;
	return 0;
}