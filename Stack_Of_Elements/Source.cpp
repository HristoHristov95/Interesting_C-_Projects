#include<iostream>
using namespace std;
#define MIN 2
class Stack {
	char* symbols;
	int totalElements;
	int elementAtTop;
public:
	Stack();
	~Stack();
	void doubleTheArray();
	void push(char);
	char pop();
	void fastStringInput(char*);
	bool isPalindrom();
};
Stack::Stack() {
	totalElements = MIN;
	symbols = (char*)malloc(totalElements * sizeof(char)); // начин в C
	 // symbols=new char[elementCount]; начин в C++
	elementAtTop = 0;
	symbols[0] = '\0';
	cout << "Constructing..." << endl;
}
Stack::~Stack() {
	if (totalElements > 0) {
		free(symbols);
		totalElements = -1;
		elementAtTop = -1;
	}
	cout << "Successfully deleted elements."<<endl;
}
void Stack::doubleTheArray() {
	char* temporary = (char*)malloc((totalElements+1) * sizeof(char));
	strcpy(temporary, symbols);
	free(symbols);
	//delete[] symbols;
	symbols = (char*)malloc(((totalElements*2) * sizeof(char)));
	totalElements *= 2;
	strcpy(symbols, temporary);
	free(temporary);
	//delete[] symbols;
}
void Stack::push(char c) {
	if ((elementAtTop+1) >= totalElements) {
		doubleTheArray();
		symbols[elementAtTop++] = c;
		symbols[elementAtTop] = '\0';
	}
	else if (elementAtTop<totalElements) {
		symbols[elementAtTop++] = c;
		symbols[elementAtTop] = '\0';
	}
	else {
		cout << "Error occurred while handling array!" << endl;
	}
}
char Stack::pop() {
	if (((elementAtTop-1) > -1) && (elementAtTop<totalElements)) {
		char c = symbols[elementAtTop-1];
		symbols[--elementAtTop] = '\0';
		return c;
	}
	else {
		return '\0';
	}
}
void Stack::fastStringInput(char* s) {
	int lenght = strlen(s);
	if (elementAtTop > -1) {
		free(symbols);
	}
	symbols = (char*)malloc((lenght+1) * sizeof(char));
	totalElements = lenght;
	elementAtTop = lenght - 1;
	strcpy(symbols, s);
	return;
}
bool Stack::isPalindrom() {
	char* stackHolder = (char*)malloc((elementAtTop+2) * sizeof(char));
	strcpy(stackHolder, symbols);
	bool isTrue = true;
	for (int i = 0,j=elementAtTop; i < (elementAtTop/2)+1; i++,j--) {
		if (symbols[i] != stackHolder[j]) {
			isTrue = false;
			free(stackHolder);
			return isTrue;
		}
	}
	return isTrue;
}

int main() {
	// Забележка: НИКОГА не използвайте malloc за да заделяте памет за обекти, в c++ !!!
	Stack* stacks = new Stack[5]; // c++ -> new за обекти ЗАДЪЛЖИТЕЛНО !!!
	stacks[0].fastStringInput("rad\0");
	stacks[1].fastStringInput("dar\0");
	stacks[2].fastStringInput("ada\0");
	stacks[3].fastStringInput("sator\0");
	stacks[4].fastStringInput("rotas\0");
	for (int i = 0; i < 5; i++) {
		cout<<boolalpha <<stacks[i].isPalindrom()<<endl;
	}
	delete[] stacks;
	return 0;
}