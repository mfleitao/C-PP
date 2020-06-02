
#include <iostream>
using namespace std;

class Student { // classes are private by default
private:
	int id;
	char name[31];
public:
	void display() {
		cout << id << " : " << name << endl;
	}

	void set(int id, char name[]) {
		id = id;
		name = name;
	}
};

void main() {

	Student glacy;
	glacy.set(234, "Glacy Leitao");
	glacy.display();
}