#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

int main() {

	char* glacy		= "Glacy Maria da Silva Leitao & Matheus Fernando Leitao";
	char* matheus	= "Matheus Fernando Leitao";
	char* ch = "abcde";

	string name(glacy);
	cout << name.substr(0, 5);

	cout << endl << endl;
	return 0;
}