#include<iostream>
#include<fstream>
#include<mutex>
#include<vector>
#include<string>
#include<thread>

using namespace std;
struct Person {
	void funct1();
	int funct2();
private:
	int a;
};
void Person::funct1() {
	cout << "Hello 1\n";
}
int Person::funct2() {
	this->a = 5;
	return a;
}
mutex stopStart[5];
int startDining(int philosopher) {
	do {
		cout << "thinking philosopher # "<<philosopher+1 << endl;
		stopStart[philosopher%5].lock();
		stopStart[(philosopher + 1) % 5].lock();
		cout << "eating philosopher # " << philosopher+1 << endl;
		this_thread::sleep_for(2s); //sus sleep se sinhronizirat ili ako imame if pak 6te stane 
		stopStart[philosopher % 5].unlock();
		stopStart[(philosopher + 1) % 5].unlock();
		cout << "finished eating #" << philosopher+1 << endl;
		cout << endl;
	} while (1);
}
int main() {
	/*thread* all[5];
	for (int i = 0; i < 5; i++) {
		all[i] = new thread(startDining, i);
	}
	for (int i = 0; i < 5; i++) {
		(*(all[i])).join();
	}*/
	Person a1;
	a1.funct1();
	cout << a1.funct2() << endl;
	return 0;

}