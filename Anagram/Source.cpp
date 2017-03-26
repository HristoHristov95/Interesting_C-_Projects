#include<iostream>
using namespace std;
bool isAnagram(const char* str1, const char* str2) {
	char* arrCh = new char[strlen(str1) + 1];
	int* arr = new int[strlen(str1) + 1];
	memcpy(arrCh, str1, sizeof(char)*(strlen(str1) + 1));
	memset(arr, 0, sizeof(int)*(strlen(str1) + 1));
	for (int i = 0; i < strlen(str1) + 1; i++) {
		for (int j = i; j < strlen(str1) + 1; j++) {
			if (arrCh[i] == arrCh[j] && arrCh[i] != ' ' && arrCh[j] != ' ') {
				if (j != i) {
					arrCh[j] = ' ';
				}
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < strlen(str1) + 1; i++) {
		for (int j = 0; j < strlen(str2) + 1; j++) {
			if (arrCh[i] != ' ') {
				if (arrCh[i] == str2[j]) {
					arr[i]--;
				}
			}
		}
	}
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		if (arr[i] > 0) {
			return false;
		}
	}
	return true;
}
int main() {
	char* s = "stop";
	char* s1 = "post";
	cout << boolalpha << isAnagram(s,s1) << endl;
	return 0;
}