#include<iostream>
#include<vector>
typedef unsigned long long ull;
class SumFct
{
public:
	static ull perimeter(int n) {
		std::vector<ull> numbers;
		ull results=0;
		for (int i = 0; i < n+1; i++) {
			if (i == 0) {
				numbers.push_back(1);
				continue;
			}
			if (i == 1) {
				numbers.push_back(1);
				continue;
			}
			numbers.push_back((numbers[i - 1] + numbers[i - 2]));
		}
		for (int i = 0; i < numbers.size(); i++) {
			results += numbers[i];
		}
		results = results * 4;
		return results;
	}
};
int main() {
	SumFct obj;
	std::cout << obj.perimeter(30) << std::endl;
	return 0;
}
