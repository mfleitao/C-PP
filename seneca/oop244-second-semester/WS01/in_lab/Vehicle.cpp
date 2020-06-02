//#include <cstring>
//#include <iostream>
//using namespace std;
//
//class Vehicle {
//	int distance;
//	char name[16];
//public:
//	Vehicle() { set("McQuenn", 100); }
//	Vehicle(const char* n, int d) { set(n, d); }
//	~Vehicle() { cout << "Pit Stop: " << name << endl; }
//	
//	void set(const char* n, int d) {
//		distance = d;
//		strncpy(name, n, 16);
//	}
//
//	int operator+(int d) {
//		Vehicle v = *this;
//		distance += d;
//		return v.distance;
//	}
//
//	int operator-(int d) {
//		return distance - d;
//	}
//
//	void show() {
//		cout << name << ", " << distance << endl;
//	}
//};
//
//int main3() {
//	Vehicle plane("Boeing", 500), car;
//	plane.show();
//	cout << plane - 100 << endl;
//	plane.show();
//	cout << car + 100 << endl;
//	cout << car - 50 << endl;
//	car.show();
//	return 0;
//}