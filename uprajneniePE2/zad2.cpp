#include<iostream>
#include<cstdlib>
using namespace std;
const int max = 50;
/*class Stack {
	char* arr;
	int elements;
public:
	Stack();
	char* loadstack();
	char* loadstack(int);
};
Stack::Stack() {
	arr = new char[max];
	if (!arr) {
		cout << "Alloc Err!\n";
	}
	elements = 0;
	memset(arr, 0, max * sizeof(char));
}
char* Stack::loadstack() {
	for (int i = 97; i < 123; i++) {
		arr[elements++] = i;
	}
	return arr;
}
char* Stack::loadstack(int used) {
	if (used) {
		for (int i = 65; i < 91; i++) {
			arr[elements++] = i;
		}
	}
	else {
		for (int i = 97; i < 122; i++) {
			arr[elements++] = i;
		}
	}
	return arr;
}
int main() {
	Stack obj;
	char* ch = obj.loadstack(1);
	while (*ch != NULL) {
		cout << *ch << endl;
		ch++;
	}
	system("PAUSE");
	return 0;
}*/