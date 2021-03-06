#include<iostream>
using namespace std;
class Fraction {
	int n, d;
public:
	Fraction(int , int );
	int getN()const;
	int getD()const;
	friend bool IsFraction(Fraction obj);
};
Fraction::Fraction(int x, int y) {
	n = x;
	if (y != 0) {
		d = y;
	}
	else {
		d = 1;
	}
}
int Fraction::getD()const {
	return d;
}
int Fraction::getN()const {
	return n;
}
bool IsFraction(Fraction obj) {
	return obj.n%obj.d != 0;
}
int main() {
	int a, b;
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;
	Fraction obj(a, b);
	if (IsFraction(obj)) {
		cout << obj.getN() << " ne se deli na " << obj.getD() << endl;
	}
	else {
		cout << obj.getN() << " se deli na " << obj.getD() << endl;
	}
	return 0;
}