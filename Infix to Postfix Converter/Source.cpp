#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int Left_association = 0;
const int Right_association = 1;
vector<char> operands = { '+','-','*','/','^','=' };
vector<int> association = { 0,0,0,0,1,1 };
vector<int> priority = { 0,0,5,5,10,-1 };
bool isOperator(char token) {
	if ((find(operands.begin(), operands.end(), token) - operands.begin()) < operands.size()) {
		return true;
	}
	return false;
}
bool isAssociative(char token, int assocNeeded) {
	if (!isOperator(token)) {
		exit(1);
	}
	int position = find(operands.begin(), operands.end(), token) - operands.begin();
	if (association[position] == assocNeeded) {
		return true;
	}
	return false;
}
int Priority(char token1, char token2) {
	if (!isOperator(token1) || !isOperator(token2)) {
		exit(2);
	}
	int position1 = find(operands.begin(), operands.end(), token1) - operands.begin();
	int position2 = find(operands.begin(), operands.end(), token2) - operands.begin();
	return priority[position1]-priority[position2];
}

std::string to_postfix(const std::string& infix) {
	vector<char> output;
	vector<char> stack;
	for (int i = 0; i < infix.size(); i++) {
		if (isdigit(infix[i])) {
			output.push_back(infix[i]);
			continue;
		}
		if (isOperator(infix[i])) {
			int temp = 0;
			int temp1 = stack.size();
			while (!stack.empty() && isOperator(stack[stack.size() - 1])) {
				if (((isAssociative(infix[i], Left_association)) && (Priority(infix[i], stack[stack.size() - 1]) <= 0)) || (isAssociative(infix[i], Right_association) && (Priority(infix[i], stack[stack.size() - 1]) < 0))) {
					output.push_back(stack[stack.size() - 1]);
					stack.erase(stack.end() - 1);
				}
				if (temp > temp1) {
					break;
				}
				temp++;
			}
			stack.push_back(infix[i]);
		}
		if (infix[i] == '(') {
			stack.push_back(infix[i]);
		}
		if (infix[i] == ')') {
			int count = stack.size() - 1;
			while (!stack.empty() && stack[count] != '(') {
				output.push_back(stack[count]);
				stack.erase(stack.begin()+count);
				count--;
			}
			stack.erase(stack.end() - 1);
		}
	}
	for (int i = stack.size() - 1; i >= 0; i--) {
		output.push_back(stack[i]);
	}
	string result(output.begin(), output.end());
	for (int i = 0; i < infix.size(); i++) {
		if (isdigit(infix[i])) {
			result.append(1, 0);
		}
	}
	return result;
}
int main() {
	cout << to_postfix("a+b+c*d^f^e=g=h/m") << endl;
	return 0;
}