#include<iostream>
#include<cstdlib>
using namespace std;
class Line {
	int lenght;
public:
	Line(int = 0);
	~Line();
};
Line::Line(int t) {
	lenght = t;
	for (int i = 0; i < lenght; i++) {
		cout << "*";
	}
	cout << endl;
	system("PAUSE");

}
Line::~Line() {
	system("CLS");
}
int main() {
	Line obj(10);
	return 0;
}