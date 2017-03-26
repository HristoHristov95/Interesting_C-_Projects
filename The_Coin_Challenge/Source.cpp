#include<iostream>
using namespace std;

int main() {
	int arr[] = { 1,3,5 };
	int count = 0;
	int sum = 11;
	int* arrayOfTemp = new int[11+1];
	for (int i = 0; i < 11+1; i++) {
		arrayOfTemp[i] = 9999;
	}
	arrayOfTemp[0] = 0;
	for (int i = 1; i < sum+1; i++) {
		for (int j = 0; j < 3-1; j++) {
			if (arrayOfTemp[i] == 9999) {
				if (arr[j] <= i && arrayOfTemp[i - arr[j]] + 1 < arrayOfTemp[i]) {
					arrayOfTemp[i] = arrayOfTemp[i - arr[j]] + 1;
				}
			}
		}
	}
	cout << arrayOfTemp[10];
	return 0;
}