
#include <iostream>
#include <thread>
using namespace std;

void task();

int main2() {

	thread t1(task);
	thread t2(task);
	t1.join();
	t2.join();

	return 0;
}

void task() {
	for (int i = 0; i < 5; i++)
		cout << "T iD: " << this_thread::get_id() << " ln: " << i << endl;
}