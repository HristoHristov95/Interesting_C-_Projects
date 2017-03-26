#include<iostream>
#include<map>
#include<string>
using namespace std;
class DivSeven
{
public:
	static std::pair <long long, long long> seven(long long m) {
		long long numberOfSteps = 1;
		std::pair<long long, long long> a;
		std::string str = std::to_string(m);
		long long current = m;
		for (;current>99;) {
			std::string substring(str.begin(), str.end() - 1);
			long long temp = atoi(substring.c_str());
			std::string substring2(str.end() - 1, str.end());
			long long lastNumber = atoi(substring2.c_str());
			current = temp - (lastNumber * 2);
			substring = std::to_string(current);
			if (substring.length() > 2) {
				str = std::to_string(current);
				numberOfSteps++;
				continue;
			}
			else {
				a = std::make_pair(atoi(substring.c_str()), numberOfSteps);
				break;
			}
		}
		return a;
	}
};
int main() {
	DivSeven obj;
	pair<long long, long long> a;
	a=obj.seven(371);
	cout << a.first << "   |   " << a.second << endl;
	return 0;
}