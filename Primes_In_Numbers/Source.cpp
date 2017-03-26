#include<iostream>
#include<string>
#include<cmath>
//const unsigned K = 25;
//const unsigned prime[K] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
class PrimeDecomp
{
public:
	/*static int isPrime(unsigned n) {
		unsigned i = 2;
		if (n == 2) return 1;
		while (i < K && prime[i]*prime[i]<=n) {
			if (n%prime[i] == 0) return 0;
			i++;
		}
		return 1;
	}*/
	static int isPrime(unsigned n) {
		unsigned i = 2;
		if (n == 2) return 1;
		while (i <= sqrt(n)) {
			if (n%i == 0) return 0;
			i++;
		}
		return 1;
	}
	static std::string factors(int lst) {
		std::string endResult;
		int currentNumberChecking = 2;
		int commonOccurence = 0;
		while (lst != 0) {
			if (isPrime(currentNumberChecking)) {
				if ((lst%currentNumberChecking) == 0) {
					lst = lst / currentNumberChecking;
					commonOccurence++;
					continue;
				}
				else {
					if (commonOccurence != 0) {
						if (commonOccurence != 1) {
							endResult.append("(");
							endResult.append(std::to_string(currentNumberChecking));
							endResult.append("**");
							endResult.append(std::to_string(commonOccurence));
							endResult.append(")");
						}
						else {
							endResult.append("(");
							endResult.append(std::to_string(currentNumberChecking));
							endResult.append(")");
						}
					}
					commonOccurence = 0;
				}
			}
			if (lst == 1) {
				lst = 0;
			}
			currentNumberChecking++;
		}
		return endResult;
	}
};
int main() {
	std::cout << PrimeDecomp::factors(86240).data() << std::endl;
	return 0;
}
