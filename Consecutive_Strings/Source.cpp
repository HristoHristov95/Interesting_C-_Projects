#include<iostream>
#include<vector>
#include<string>
using namespace std;

class LongestConsec
{
public:
	static std::string longestConsec(std::vector<std::string> &strarr, int k) {
		std::string result;
		long long size = 0;
		long long currentLongestSize = 0;
		long long start = 0;
		long long end = 0;
		long long current = 0;
		if (k <= 0) {
			return "";
		}
		if (strarr.size() < k) {
			return "";
		}
		if (strarr.size() == 0) {
			return "";
		}
		for (long long i = 0; i < strarr.size(); i++) {
			size = strarr[i].length();
			current++;
			if (k == 1) {
				if (currentLongestSize < size) {
					currentLongestSize = size;
					start = i;
					end = i;
				}
				continue;
			}
			for (long long j = i + 1; j < strarr.size(); j++) {
				if (current == k) {
					if (currentLongestSize < size) {
						currentLongestSize = size;
						start = i;
						end = j;
					}
					break;
				}
				size = size + strarr[j].length();
				current++;
				if (currentLongestSize < size) {
					currentLongestSize = size;
					start = i;
					end = j;
				}
			}
			size = 0;
			current = 0;
		}
		for (int i = start;i<=end; i++) {
			result.append(strarr[i]);
		}
		return result;
	}
};
int main() {
	vector<string> s = { "it","wkppv","ixoyx", "3452", "zzzzzzzzzzzz" };
	cout << LongestConsec::longestConsec(s, 3).data() << endl;
	return 0;
}