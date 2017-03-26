#include<iostream>
using namespace std;
static int arr[] = { 1,2,3,4,5,6,9 };
int& calculate(int& number) {
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		if (number == arr[i]) {
			return number;
		}
	}
	number = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		number += arr[i];
	}
	return number;
}
int main() {
	int a = 9;
	cout << calculate(a) << endl;
	return 0;
}