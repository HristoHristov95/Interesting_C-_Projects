#include<iostream>
#include<vector>
#include<string>
using namespace std;
class tower {

public:
	std::vector<std::string> towerBuilder(int nFloors)
	{
		std::vector<char> a;
		std::vector<std::string> b;
		long long current = 1;
		long long begin = 1;
		char symbol = '*';
		for (long long i = 0; i < nFloors; i++) {
			for (long long k = 0; k < nFloors-begin; k++) {
				a.push_back(' ');
			}
			for (long long k = 0; k < current; k++) {
				a.push_back(symbol);
			}
			for (long long k = 0; k < nFloors - begin; k++) {
				a.push_back(' ');
			}
			current += 2;
			begin++;
			std::string str(a.begin(), a.end());
			b.push_back(str);
			a.clear();
		}
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << endl;
		}
		return b;
	}
};
int main() {
	int a = 3;
	tower obj;
	obj.towerBuilder(a);
	return 0;
}