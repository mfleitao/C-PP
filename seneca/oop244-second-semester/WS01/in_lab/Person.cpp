#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char name[31];
protected:
	void displayName(std::ostream&) const;
public:
	Person();
	Person(const char* n);
	virtual void display(std::ostream&) const;
};

Person::Person() { name[0] = '\0'; }
Person::Person(const char* n) {
	strncpy(name, n, 31);
	name[31] = '\0';
}

void Person::display(std::ostream& os) const { 
	os << "Person: " << name << endl;
}

void Person::displayName(std::ostream& os) const {
	os << name;
}

class Student : public Person {
public:
	Student(const char*);
	void display(std::ostream&) const;
};

Student::Student(const char* n) : Person(n) {}
void Student::display(std::ostream& os) const {
	os << "Student: ";
	displayName(os);
	os << endl;
}

void show(const Person& p) {
	p.display(cout);
}

int main4() {
	Person jane("jane");
	Student harry("Harry");
	jane.display(cout);
	harry.display(cout);
	show(jane);
	show(harry);
	jane.Person::display(cout);
	harry.Person::display(cout);
	return 0;
}


