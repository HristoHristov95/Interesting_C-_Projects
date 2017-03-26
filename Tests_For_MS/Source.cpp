#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
void swap(string& s1, string& s2) {
	string s = s1;
	s1 = s2;
	s2 = s;
}
void swapMy(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
class A {
public:
	virtual void printA() {
		cout << "A";
	}
};
class B : public A {
public:
	void printA() {
		cout << "B";
	}
};
class C : public A {
public:
	void printA() {
		cout << "C";
	}
};
class D : public A {
public:
	void printA() {
		cout << "D";
	}
};

/*class MyClass {
	static MyClass* object;
	MyClass() {}
	MyClass(const MyClass&)=delete;
	MyClass& operator=(const MyClass&)=delete;
public:
	static MyClass* getMyClass();
	void abs(int ext);
	void abs(float ext);
	void abs(double ext)=delete;
};
MyClass* MyClass::object = NULL;
MyClass* MyClass::getMyClass() {
	if (object == NULL) {
		object = new MyClass();
	}
	return object;
}
void MyClass::abs(int ext) {
	cout << "Int"<<endl;
}
void MyClass::abs(float ext) {
	cout << "float"<<endl;
}*/
class test1 {
	char* str;
	int a;
public:
	void printA() {
		cout << a << endl;
		cout << str << endl;
	}
	~test1();
};
test1::~test1() {
	cout << "Test1 dest" << endl;
}
class test2 : public test1 {
public:
	~test2() {
		cout << "Test2 dest" << endl;
	}
};

int main() {
	//MyClass* obj= MyClass::getMyClass();
	//obj->abs(static_cast<float>(11));
//	int arra[] = { 6,17,33,1,5,2,6 };
//	quick_sort(arra, 0, 6);
//	heap_sort(arra, 7);
//	heap_sort(arra, 7);
//	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
//	cout<<calculate(arr,7);
	// SPLIT SENTENCE INTO WORDS GO!
	string s = "Hello guys how are you all doing!\n";

	// lexical sort GO !

	string array1[] = {"Hello","aab","aabb","acb","aqwe"};

	test1 obj;
//	obj.printA();
	cout << endl << endl << endl;
	char* strtemp = new char[4];
	strtemp[0] = 'a';
	strtemp[1] = 'b';
	strtemp[2] = 'c';
	strtemp[3] = '\0';
	cout << strlen(strtemp) << endl;

	const char* strrr = "123";
	char* str2 = new char[strlen(strtemp)+1];
	cout << strlen(strrr) << endl;
	strcpy(str2, strtemp);
	cout << str2 << endl;
	delete[] strtemp;
	delete[] str2;
	return 0;
}
