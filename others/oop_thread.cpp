#include <iostream>
#include <thread>
using namespace std;

void myFunc(string msg) {
	cout << msg << endl;
}

int main()
{
    thread t1(myFunc, "This is thread 1");
	thread t2(myFunc, "This is thread 2");
	thread t3(myFunc, "This is thread 3");

	// Wait for the threads to finish
	// Wait for thread t1 to finish
	t1.join();

	// Wait for thread t2 to finish
	t2.join();

	// Wait for thread t3 to finish
	t3.join();

	return 0;
}
