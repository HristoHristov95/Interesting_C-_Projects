#include<iostream>
using namespace std;
class Indexed {
	int* number;
	int size;
protected:
	int lowerbound;
	int upperbound;
public:
	Indexed(int = 1);
	~Indexed();
	int& operator[](int);
	Indexed& operator=(Indexed&);
	virtual Indexed* create();
	virtual void insertElement(int,int);
	virtual void deleteElement(int);
	Indexed* intersection(Indexed);
	Indexed* unionIndex(Indexed);
	Indexed* setDifference(Indexed);
};
Indexed::Indexed(int size) {
	if (size < 0) {
		cout << "Invalid number for size of array !\n";
		exit(1);
	}
	this->size = size;
	lowerbound = 0;
	upperbound = size - 1;
	number = new int[size];
	if (!number) {
		cout << "Error while allocating memory !\n";
		exit(1);
	}
}
Indexed::~Indexed() {
	delete[] number;
}
int& Indexed::operator[](int position) {
	if (position >= lowerbound && position <= upperbound) {
		return number[position];
	}
	else {
		cout << "Out of bound exeption error here !!!.... exit!\n";
		exit(1);
	}
}
Indexed& Indexed::operator=(Indexed& object) {
	if (this != &object) {
		if (this->size != object.size) {
			delete[] this->number;
			this->size = object.size;
			this->number = new int[size];
			if (!this->number) {
				cout << "Error allocating memory !\n";
				exit(2);
			}
		}
		for (int i = 0; i < size; i++) {
			number[i] = object.number[i];
		}
		lowerbound = object.lowerbound;
		upperbound = object.upperbound;
	}
	return *this;
}
Indexed* Indexed::create() {
	int size;
	cout << "Enter size of array: " << endl;
	cin >> size;
	Indexed* object = new Indexed(size);
	cout << "Enter your elements : " << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter element : ";
		cin >> (*object)[i];
		cout << '\n';
	}
	return object;
}
void Indexed::insertElement(int element,int position) {
	if (position<lowerbound || position>upperbound) {
		cout << "Error in bound!\n";
		exit(3);
	}
	int* temporary = new int[upperbound + 2];
	for (int i = 0,m=0; i < upperbound + 2; i++,m++) {
		if(i==position){
			temporary[i] = element;
			m--;
			continue;
		}
		temporary[i] = (*this)[m];
	}
	delete[] number;
	number = new int[upperbound + 2];
	for (int i = 0; i < upperbound + 2; i++) {
		this->number[i] = temporary[i];
	}
	delete[] temporary;
}
void Indexed::deleteElement(int position) {
	if (position<lowerbound || position>upperbound) {
		cout << "Error in position!\n";
		exit(2);
	}
	for (int i = 0,k=0; i <= upperbound; i++,k++) {
		if (k > upperbound) {
			break;
		}
		if (i == position) {
			k++;
		}
		(*this)[i] = (*this)[k];
	}
}
Indexed* Indexed::intersection(Indexed object) {
	int totalElements = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if (this->number[i] == object.number[k]) {
				totalElements++;
			}
		}
	}
	Indexed* result = new Indexed(totalElements);
	int currentElement = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if (this->number[i] == object.number[k]) {
				result->number[currentElement++] = number[i];
			}
		}
	}
	return result;
}
Indexed* Indexed::unionIndex(Indexed object) {
	Indexed temporaryObj = object;
	int* arrayPos=new int[this->size+object.size];
	int count = 0;
	bool check = false;
	memcpy(arrayPos, 0, this->size + object.size);
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= temporaryObj.upperbound; k++) {
			if (this->number[i] == temporaryObj.number[k]) {
				arrayPos[count++] = this->number[i];
				temporaryObj.number[k] = -9999;
				check = true;
			}
		}
		if (!check) {
			arrayPos[count++] = this->number[i];
			check = false;
		}
	}
	for (int i = 0; i < temporaryObj.size; i++) {
		if (temporaryObj.number[i] != -9999) {
			arrayPos[count++] = temporaryObj.number[i];
		}
	}
	Indexed* result = new Indexed(count);
	int currentElement = 0;
	for (int i = 0; i < count; i++) {
		(*result)[i] = arrayPos[i];
	}
	delete[] arrayPos;
	return result;
}
Indexed* Indexed::setDifference(Indexed object) {
	int totalElements = 0;
	bool check = false;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if (this->number[i] == object.number[k]) {
				check = true;
			}
		}
		if (!check) {
			totalElements++;
			check = false;
		}
	}
	check = false;
	Indexed* result = new Indexed(totalElements);
	int currentElement = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if (this->number[i] == object.number[k]) {
				check = true;
			}
		}
		if (!check) {
			(*result)[currentElement++] = this->number[i];
			check = false;
		}
	}
	return result;
}


class Sorted : public Indexed {

public:
	Sorted(int);
	int& operator[](int);
	void sort();
	Sorted* create();
	void insertElement(int, int);
	Sorted* intersection(Sorted object);
	Sorted* unionIndex(Sorted object);
	Sorted* setDifference(Sorted object);
};
Sorted::Sorted(int size) :  Indexed(size) {
}
int& Sorted::operator[](int position) {
	if (position<lowerbound || position>upperbound) {
		cout << "Error in position!\n";
		exit(2);
	}
	return Indexed::operator[](position);
}
void Sorted::sort() {
	for (int i = 0; i <= upperbound; i++) {
		for (int k = i; k <= upperbound; k++) {
			if ((*this)[i] > (*this)[k]) {
				int temp = (*this)[i];
				(*this)[i] = (*this)[k];
				(*this)[k] = temp;
			}
		}
	}
}
Sorted* Sorted::create() {
	int size;
	cout << "Enter size of array: " << endl;
	cin >> size;
	Sorted* object = new Sorted(size);
	cout << "Enter your elements : " << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter element : ";
		cin >> (*object)[i];
		cout << '\n';
	}
	object->sort();
	return object;
}
void Sorted::insertElement(int element, int position) {
	if (position<lowerbound || position>(upperbound+1)) {
		cout << "Error in bound!\n";
		exit(3);
	}
	int* temporary = new int[upperbound + 2];
	for (int i = 0, m = 0; i < upperbound + 2; i++, m++) {
		if (i == position) {
			temporary[i] = element;
			m--;
			continue;
		}
		temporary[i] = (*this)[m];
	}
	for (int i = 0; i < upperbound + 2; i++) {
		(*this)[i] = temporary[i];
	}
	this->sort();
	delete[] temporary;
}
Sorted* Sorted::intersection(Sorted object) {
	int totalElements = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if ((*this)[i] == object[k]) {
				totalElements++;
			}
		}
	}
	Sorted* result = new Sorted(totalElements);
	int currentElement = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if ((*this)[i] == object[k]) {
				(*result)[currentElement++] = (*this)[i];
			}
		}
	}
	result->sort();
	return result;
}
Sorted* Sorted::unionIndex(Sorted object) {
	Sorted temporaryObj = object;
	int* arrayPos = new int[this->upperbound + object.upperbound+1];
	int count = 0;
	bool check = false;
	memcpy(arrayPos, 0, this->upperbound + object.upperbound + 1);
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= temporaryObj.upperbound; k++) {
			if ((*this)[i] == temporaryObj[k]) {
				arrayPos[count++] = (*this)[i];
				temporaryObj[k] = -9999;
				check = true;
			}
		}
		if (!check) {
			arrayPos[count++] = (*this)[i];
			check = false;
		}
	}
	for (int i = 0; i < temporaryObj.upperbound+1; i++) {
		if (temporaryObj[i] != -9999) {
			arrayPos[count++] = temporaryObj[i];
		}
	}
	Sorted* result = new Sorted(count);
	int currentElement = 0;
	for (int i = 0; i < count; i++) {
		(*result)[i] = arrayPos[i];
	}
	result->sort();
	delete[] arrayPos;
	return result;
}
Sorted* Sorted::setDifference(Sorted object) {
	int totalElements = 0;
	bool check = false;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if ((*this)[i] == object[k]) {
				check = true;
			}
		}
		if (!check) {
			totalElements++;
			check = false;
		}
	}
	check = false;
	Sorted* result = new Sorted(totalElements);
	int currentElement = 0;
	for (int i = 0; i <= this->upperbound; i++) {
		for (int k = 0; k <= object.upperbound; k++) {
			if ((*this)[i] == object[k]) {
				check = true;
			}
		}
		if (!check) {
			(*result)[currentElement++] = (*this)[i];
			check = false;
		}
	}
	result->sort();
	return result;
}
int main() {

	return 0;
}


