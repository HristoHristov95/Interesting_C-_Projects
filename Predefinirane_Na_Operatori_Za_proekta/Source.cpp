#include<iostream>
#include<ctime>
using namespace std;
class Watch {
	struct tm* time;
	int year;
	int month;
	int day;
public:
	Watch(time_t now=0);
	friend ostream& operator<<(ostream& stream, Watch&);
	friend istream& operator >> (istream& stream, Watch&);
	operator int();
};
Watch::Watch(time_t now) {
	time = localtime(&now);
}
ostream& operator<<(ostream& stream, Watch& object) {
	stream << "Year is : " << object.time->tm_year + 1900 << endl;
	stream << "Month is: " << object.time->tm_mon + 1 << endl;
	stream << "Day is : " << object.time->tm_mday << endl;
	stream << "Time is: " << object.time->tm_hour <<":"<<object.time->tm_min<<":"<<object.time->tm_sec<<endl;
	return stream;
}
istream& operator >> (istream& stream, Watch& object) {
	cout << "Enter year: ";
	stream >> object.year;
	cout << "\nEnter month: ";
	stream >> object.month;
	cout << "\nEnter day: ";
	stream >> object.day;
	return stream;
}
Watch::operator int() {
	return year*month*day;
}
int main() {
	Watch object(time(0));
	cout << object << endl;
	cin >> object;
	int result = object;
	cout << "Result: " << result << endl;
	return 0;
}
