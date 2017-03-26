#include<iostream>
#include<complex>
#include<typeinfo>
using namespace std;
class SingleLineArray {
public:
	virtual void Print() const = 0;
};
class NonFloat : public SingleLineArray {
	int number;
public:
	NonFloat(int = 1);
	void Print() const;
};
NonFloat::NonFloat(int numb) {
	number = numb;
}
void NonFloat::Print()const {
	cout << number << " ";
}

class DoubleNumbers : public SingleLineArray {
	double number;
public:
	DoubleNumbers(double = 1);
	void Print()const;
};
DoubleNumbers::DoubleNumbers(double numb) {
	number = numb;
}
void DoubleNumbers::Print()const {
	cout << number << " ";
}
class ImaginaryNumbers : public SingleLineArray {
	complex<double> z;
public:
	ImaginaryNumbers(complex<double> = 1);
	void Print()const;
};
ImaginaryNumbers::ImaginaryNumbers(complex<double> numb) {
	z = numb;
}
void ImaginaryNumbers::Print()const {
	cout << "Real part : " << z.real() << " Imaginary part: " << z.imag() << endl;
}
int main() {
	SingleLineArray* object[] = { &NonFloat(5),&NonFloat(7),&DoubleNumbers(4.22),&NonFloat(11),&DoubleNumbers(3.666),&NonFloat(325),&ImaginaryNumbers(complex<double>(2,1)),&NonFloat(23) };
	int numbersCount[3] = { 0,0,0 };
	cout << "NonDouble : ";
	for (int i = 0; i < sizeof(object) / sizeof(SingleLineArray); i++) {
		if (typeid(*object[i]).name() == typeid(NonFloat).name()) {
			object[i]->Print();
			numbersCount[0]++;
		}
	}
	cout << endl;
	cout << "Double : ";
	for (int i = 0; i < sizeof(object) / sizeof(SingleLineArray); i++) {
		if (typeid(*object[i]) == typeid(DoubleNumbers)) {
			object[i]->Print();
			numbersCount[1]++;
		}
	}
	cout << endl;
	cout << "Imaginary : ";
	for (int i = 0; i < sizeof(object) / sizeof(SingleLineArray); i++) {
		if (typeid(*object[i]) == typeid(ImaginaryNumbers)) {
			object[i]->Print();
			numbersCount[2]++;
		}
	}
	cout << endl;
	cout << "The Non Double numbers are : " << numbersCount[0] << " \nThe double numbers are: " << numbersCount[1] << " \nAnd the imaginary numbers are: " << numbersCount[2] << endl;
	return 0;
}