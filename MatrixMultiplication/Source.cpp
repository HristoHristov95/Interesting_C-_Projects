#include<iostream>
using namespace std;
class Matrix {
public:
	long long** calculate(long long** m1, long long** m2) {
		long long** matrix = new long long*[3];
		for (int i = 0; i < 3; i++) {
			matrix[i] = new long long[3];
		}
		long long temp = 0;
		int count = 0;
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				temp += m1[i][k] * m2[k][i];
			}
			matrix[i][count++] = temp;
			temp = 0;
			if (count >= 3) {
				count = 0;
			}
		}
		return matrix;
	}
};
int main() {
	long long** m1 = new long long*[3];
	long long** m2 = new long long*[3];
	for (int i = 0; i < 3; i++) {
		m1[i] = new long long[3];
		m2[i] = new long long[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {

		}
	}
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {

		}
	}
	return 0;
}