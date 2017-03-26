#include<iostream>
#define MAX 10000
using namespace std;
class Fact {
	int numb;
	int result[MAX];
	long total;
public:
	Fact(int n);
	void calculate();
	void print();
};
Fact::Fact(int n) {
	numb = n;
	result[0] = 1;
	total = 0;
}
void Fact::calculate() {
	long count = 1;
	long current = 0;
	for (int i = 2; i<= numb; i++) {
		for (long j = 0; j < count; j++) {
			int res = result[j] * i + current;
			result[j] = res % 10;
			current = res / 10;
		}
		while (current) {
			result[count++] = current %10;
			current = current / 10;
		}
	}
	total = count;
}
void Fact::print() {
	for (long i = total - 1; i >= 0; i--) {
		cout << result[i];
	}
}
int main() {
	Fact obj(200);
	obj.calculate();
	obj.print();
	return 0;
}