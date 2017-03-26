#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
class BackWardsPrime
{
public:
	static int isPrime(long long n) {
		long long i = 2;
		if (n == 2) return 1;
		while (i <= sqrt(n)) {
			if (n%i == 0) return 0;
			i++;
		}
		return 1;
	}
	static std::string backwardsPrime(long long start, long long end) {
		std::string result;
		std::vector<long long> allNumbers;
		for (long long i = start; i <= end; i++) {
			if (i > 10) {
				if (isPrime(i)) {
					std::string s = std::to_string(i);
					std::reverse(s.rbegin(), s.rend());
					long long t = atoll(s.c_str());
					if (i != t) {
						if (isPrime(t)) {
							if ((i >= start) && (i <= end)) {
								allNumbers.push_back(i);
							}
							if ((t >= start) && (t <= end)) {
								allNumbers.push_back(t);
							}
						}
					}
				}
			}
		}
		std::sort(allNumbers.begin(), allNumbers.end());
		allNumbers.erase(std::unique(allNumbers.begin(), allNumbers.end()), allNumbers.end());
		std::vector<long long>::iterator s = allNumbers.begin();
		for (int i = 0; i < allNumbers.size(); i++) {
			result.append(std::to_string(*s));
			if ((i != allNumbers.size() - 1)) {
				result.append(" ");
			}
			s++;
		}
		return result;
	}
};
int main() {
	cout << BackWardsPrime::backwardsPrime(2, 100) << endl;
	return 0;
}