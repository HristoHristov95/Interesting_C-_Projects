#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	double a[3];
	cout << "Enter three numbers: ";
	string s;
	int c = 0;
	while (c != 3) {
		getline(cin, s);
		if (find_if(s.begin(), s.end(), [](char c) {return !isdigit(c); }) == s.end()) {
			a[c] = atof(s.c_str());
		}
		else {
			exit(1);
		}
		s.erase(s.begin(), s.end());
		cin.clear();
		c++;
	}
	
	return 0;
}