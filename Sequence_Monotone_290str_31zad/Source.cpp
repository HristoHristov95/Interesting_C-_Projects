#include<iostream>
using namespace std;
template<class T>
class Sequence {
	T* elements;
	int size;
protected:
	int lowerbound;
	int upperbound;
public:
	Sequence(int = 1);
	Sequence(const Sequence&);
	~Sequence();
	Sequence& operator=(const Sequence&);
	T& operator[](int);
	virtual void printElements();
};
template<class T> 
Sequence<T>::Sequence(int size) {
	this->size = size;
	this->elements = new T[size];
	if (!elements) {
		cout << "Error allocating memory!\n";
		exit(1);
	}
	lowerbound = 0;
	upperbound = size - 1;
}
template<class T> 
Sequence<T>::Sequence(const Sequence<T>& object) {
	if (this != &object) {
		if (this->size != object.size) {
			this->size = object.size;
			delete[] elements;
			elements = new T[size];
		}
		for (int i = 0; i < object.size; i++) {
			this->elements[i] = object.elements[i];
		}
		lowerbound = object.lowerbound;
		upperbound = object.upperbound;
	}
}
template<class T> 
Sequence<T>::~Sequence() {
	delete[] elements;
}
template<class T> 
Sequence<T>& Sequence<T>::operator=(const Sequence<T>& object) {
	this->size = object.size;
	delete[] elements;
	elements = new T[this->size];
	if (!elements) {
		cout << "Error while allocating memory ! EXIT... \n ";
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		elements[i] = object.elements[i];
	}
	lowerbound = object.lowerbound;
	upperbound = object.upperbound;
	cout << "Sequence = Operator Used !!!\n";
	return *this;
}
template<class T> 
T& Sequence<T>::operator[](int position) {
	if (position >= lowerbound && position <= upperbound) {
		return elements[position];
	}
	cout << "Error in position out of bounds!\n";
	exit(1);
}
template<class T> 
void Sequence<T>::printElements() {
	for (int i = 0; i <= upperbound; i++) {
		cout << (*this)[i] << " ";
	}
	cout << endl;
}


template<class T> 
class Monotone : public Sequence<T> {
public:
	Monotone(int=1);
	~Monotone();
	Monotone(const Monotone&);
	// защо няма нужда да се пренапише operator= ?
	T& operator[](int);
	void type();
};
template<class T> 
Monotone<T>::Monotone(int size) : Sequence<T>(size) {
	lowerbound = 0;
	upperbound = size - 1;
}
template<class T> 
Monotone<T>::~Monotone() {
	cout << "Black magic is happening here :D it knows what to do dont worry be happy !\n";
}
template<class T> 
Monotone<T>::Monotone(const Monotone<T>& object) : Sequence<T>(object) {
}
template<class T>
T& Monotone<T>::operator[](int position) {
	if (position >= lowerbound && position <= upperbound) {
		return Sequence<T>::operator[](position);
	}
}
template<class T> 
void Monotone<T>::type() {
	T temp = (*this)[lowerbound] - (*this)[lowerbound+1];
	bool isHigher=true;
	bool isLower=true;
	for (int i = lowerbound+1; i < upperbound; i++) {
		if ((*this)[i] + temp > (*this)[i + 1]) {
			;
		}
		else {
			isLower = false;
		}
		if ((*this)[i] + temp < (*this)[i + 1]) {
			;
		}
		else {
			isHigher = false;
		}
	}
	if (isLower) {
		cout << "Redicata e namalqvashta!\n";
	}
	else if (isHigher) {
		cout << "Redicata e rastqshta!\n";
	}
	else {
		cout << "Nito namalqvashta nito rastqshta!\n";
	}
}
int main() {
	Sequence<int> object(4);
	object[0] = 1;
	object[1] = 2;
	object[2] = 3;
	object[3] = 4;
	object.printElements();
	Monotone<int> objects(5);
	objects[0] = 1;
	objects[1] = 2;
	objects[2] = 3;
	objects[3] = 4;
	objects[4] = 5;
	objects.type();
	Monotone<int> tempraryObject;
	tempraryObject = objects;
	tempraryObject[1] = 4;
	tempraryObject.printElements();
	return 0;
}