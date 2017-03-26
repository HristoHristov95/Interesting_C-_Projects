#include<iostream>
#include<ctime>
using namespace std;
/*class Time {
	int hr;
	int min;
	int sec;
	time_t t;
	struct tm* time1;
public:
	Time(int hr, int min, int sec);
	Time();
	void setTime(int hr, int min, int sec);
	void setTime(time_t t);
	void printType1();
	void printType2();
};
Time::Time(int hr, int min, int sec) {
	if (hr < 24 && min < 60 && sec < 60) {
		this->hr = hr;
		this->min = min;
		this->sec = sec;
	}
	else {
		cout << "Wrong time!\n";
	}
}
Time::Time() {
	this->t = time(0);
	time1 = localtime(&t);
	hr = time1->tm_hour;
	min = time1->tm_min;
	sec = time1->tm_sec;
}
void Time::setTime(int hr, int min, int sec) {
	if (hr < 24 && min < 60 && sec < 60) {
		this->hr = hr;
		this->min = min;
		this->sec = sec;
	}
	else {
		cout << "Wrong time!\n";
	}
}
void Time::setTime(time_t t) {
	this->t = t;
	time1 = localtime(&t);
}
void Time::printType1() {
	cout << "Hr: " << time1->tm_hour << " Min: " << time1->tm_min << " Sec: " << time1->tm_sec << endl;
}
void Time::printType2() {
	cout << "Hr: " << hr << " Min: " << min << " Sec: " << sec << endl;
}
int main() {
	Time s;
	s.printType1();
	s.printType2();
	return 0;
}*/