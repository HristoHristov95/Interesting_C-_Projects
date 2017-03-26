#include<iostream>
using namespace std;
class MyClass {
	static MyClass* object;
	MyClass() {}
public:
	static MyClass* getMyObject();
};
MyClass* MyClass::object = NULL;
MyClass* MyClass::getMyObject() {
	if (object != NULL) {
		object = new MyClass();
	}
	return object;
}
int main() {

	return 0;
}