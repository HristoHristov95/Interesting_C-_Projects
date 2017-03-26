#include<iostream>
using namespace std;
class Calculator {
	char operators[4] = { '+','-','*','/' };
	int priority[4] = { 0,0,5,5 };
public:
	bool isValid(char*);
	int calculate(char*);
	int Priority(char, char);
};
bool isOperator(char c) {
	switch(c) {
		case '+': return true;
		case '-': return true; 
		case '*': return true;
		case '/': return true;
		default: return false;
	}
}
int Calculator::Priority(char c1, char c2) {
	int c1P = 0;
	int c2P = 0;
	for (int i = 0; i < 4; i++) {
		if (c1 == operators[i]) {
			c1P = priority[i];
		}
		if (c2 == operators[i]) {
			c2P = priority[i];
		}
	}
	return c1P - c2P;
}
bool Calculator::isValid(char* string) {
	bool valid = true;
	for (int i = 0; i < strlen(string); i++) {
		if (i == 0) {
			if (isdigit(string[i])) {
				continue;
			}
			else {
				valid = false;
			}
		}
		if (isdigit(string[i])) {
			continue;
		}
		else {
			if (!isOperator(string[i])) {
				valid = false;
			}
			
		}
	}
	return valid;
}

int Calculator::calculate(char* string) {
	
}
int main() {
	Calculator obj;
	cout << obj.calculate("5+4+3*2*2+1")<<endl;
	return 0;
}