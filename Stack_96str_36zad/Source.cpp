#include<iostream>
using namespace std;
const int MaxStack = 100;
const int FullStack = MaxStack;
const int EmptyStack = -1;
const char EmptyFlag = '\0';
class StackIterator;
class Stack {
	friend StackIterator;
	char items[MaxStack];
	int top;
public:
	Stack();
	Stack(const Stack&);
	void push(char c);
	char pop();
	bool empty();
	bool full();
	void print();
};
Stack::Stack() {
	top = EmptyStack;
}
Stack::Stack(const Stack& obj) {
	top = obj.top;
	for (int i = 0; i <= top; i++) {
		items[i] = obj.items[i];
	}
}
void Stack::push(char c) {
	if(full()) {
		cout << "Stack full!\n";
		return;
	}
	items[++top] = c;
}
char Stack::pop() {
	if (empty()) {
		cout << "Stack is empty!\n";
		return EmptyFlag;
	}
	return items[top--];
}
bool Stack::empty() {
	return top == EmptyStack;
}
bool Stack::full() {
	return top == FullStack - 1;
}
void Stack::print() {
	for (int i = top; i >= 0; i--) {
		cout << pop() << endl;
	}
}
class StackIterator {
	Stack* stck;
public:
	StackIterator(Stack s) {
		stck = &s;
	}
	char* getNext();
};
char* StackIterator::getNext() {
	if (stck->top == EmptyStack) {
		return;
	}
	return &stck->items[stck->top--];
}
int main() {
	Stack s;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	Stack t = s;
	s.print();
	StackIterator s1(t);
	char* pointer;
	while (pointer = s1.getNext()) {
		cout << *pointer << endl;
	}
	return 0;
}