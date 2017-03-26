#include<iostream>
#include<vector>
using namespace std;
class Decomp
{
public:
	static vector<long long> decompose(long long n) {
		vector<long long> tests;
		vector<long long> numbers;
		vector<long long>results;
		long long checker = n*n;
		long long currentResult = 0;
		for (long long i = n - 1; i >= 1; i--) {
			tests.push_back(i*i);
		}
		for (long long i = 0; i < tests.size(); i++) {
			numbers.push_back(i);
			currentResult += tests[numbers[numbers.size() - 1]];
			for (long long j = i + 1; j < tests.size(); j++) {
				if ((tests[j] + currentResult <= checker) && (j != numbers[numbers.size()-1])) {
					numbers.push_back(j);
					currentResult += tests[j];
				}
				if (currentResult == checker)
				{
					for (long long q = numbers.size()-1; q >= 0; q--) {
						results.push_back(sqrt(tests[numbers[q]]));
					}
					return results;
				}
				if (j == tests.size() - 1) {
					if (numbers[numbers.size() - 1] < tests.size() - 1) {
						if (numbers.size() >= 1) {
							currentResult = 0;
							j = numbers[numbers.size() - 1];
							numbers.erase(numbers.end() - 1);
							for (long long k = 0; k < numbers.size(); k++) {
								currentResult += tests[numbers[k]];
							}
						}
					}
					else {
						currentResult = 0;
						if (numbers.size() >= 2) {
							j = numbers[numbers.size() - 2];
							numbers.erase(numbers.end() - 1);
							numbers.erase(numbers.end() - 1);
							for (long long k = 0; k < numbers.size(); k++) {
								currentResult += tests[numbers[k]];
							}
						}
						else {
							break;
						}
					}
				}
			}
			currentResult = 0;
			numbers.erase(numbers.begin(), numbers.end());
		}
		return{};
	}
};
int main() {
	vector<long long> numbers= Decomp::decompose(0);
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	return 0;
}