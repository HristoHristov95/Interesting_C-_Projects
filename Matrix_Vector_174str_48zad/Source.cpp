#include<iostream>
using namespace std;
#define MAX 3
class Vector;
class Matrix {
	int matrx[MAX][MAX];
public:
	Matrix();
	friend void matrix_vector(Matrix mat,Vector vec);
};
class Vector {
	int vector[MAX];
public:
	Vector();
	friend void matrix_vector(Matrix mat, Vector vec);
};
Matrix::Matrix() {
	for (int i = 0; i < MAX; i++) {
		for (int k = 0; k < MAX; k++) {
			cout << "Enter number for matrix: " << endl;
			cin >> matrx[i][k];
		}
	}
}
Vector::Vector() {
	for (int i = 0; i < MAX; i++) {
		cout << "Enter number for vector: " << endl;
		cin >> vector[i];
	}
}
void matrix_vector(Matrix mat, Vector vec) {
	for (int i = 0; i < MAX; i++) {
		for (int k = 0; k < MAX; k++) {
			mat.matrx[k][i] = mat.matrx[k][i]*vec.vector[i];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int k = 0; k < MAX; k++) {
			cout << mat.matrx[i][k] << " ";
		}
		cout << endl;
	}
}
int main() {
	Matrix obj1;
	Vector obj2;
	matrix_vector(obj1, obj2);
}