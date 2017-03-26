#include<iostream>
#include<vector>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
string trim(string stringToTrim) {
	size_t last = stringToTrim.find_last_not_of(' ');
	return stringToTrim.substr(0, last+1);
}
std::string histogram(std::vector<int> results)
{
	vector<string> reversedLook;
	vector<bool> isNumberRdy;
	vector<int>temp(results.begin(), results.end());
	string fill;
	stringstream ss;
	int max = max_element(results.begin(),results.end())-results.begin();
	max = results[max];
	for (int i = 0; i < results.size(); i++) {
		if (results[i] != 0) {
			isNumberRdy.push_back(false);
		}
		else {
			isNumberRdy.push_back(true);
		}
	}
	for (int i = 1; i <= results.size(); i++) {
		ss << i;
		fill.append(ss.str());
		ss.str("");
		if (i != results.size()) {
			fill.append(1, ' ');
		}
	}
	fill.append(1, '\n');
	reversedLook.push_back(fill);
	fill.erase(fill.begin(), fill.end());
	for (int i = 0; i < reversedLook[0].size()-1; i++) {
		fill.append(1, '-');
	}
	fill.append(1, '\n');
	reversedLook.push_back(fill);
	fill.erase(fill.begin(), fill.end());
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] > 0) {
				fill.append(1, '#');
				fill.append(1, ' ');
				temp[j]--;
			}
			else {
				if (results[j] != 0) {
					if (!isNumberRdy[j]) {
						ss << results[j];
						fill.append(ss.str());
						ss.str("");
						isNumberRdy[j] = true;
						if (results[j] < 10) {
							fill.append(1, ' ');
						}
						continue;
					}
				}
				bool isEnd = true;
				int current = j;
				while (current < temp.size()) {
					if ((temp[current] > 0) || ((results[current] != 0) && (!isNumberRdy[current]))) {
						isEnd = false;
					}
					current++;
				}
				if (isEnd) {
					fill = trim(fill);
					fill.append(1,'\n');
					reversedLook.push_back(fill);
					fill.erase(fill.begin(), fill.end());

					break;
				}
				else {
					fill.append(1, ' ');
					fill.append(1, ' ');
				}
			}
		}
		if (!fill.empty()) {
			fill = trim(fill);
			fill.append(1, '\n');
			reversedLook.push_back(fill);
			fill.erase(fill.begin(), fill.end());
		}
	}
	fill.erase(fill.begin(), fill.end());
	bool hasNext = false;
	for (int i = 0; i < isNumberRdy.size(); i++) {
		if (results[i] != 0) {
			if (!isNumberRdy[i]) {
				ss << results[i];
				fill.append(ss.str());
				ss.str("");
				for (int j = i + 1; j < isNumberRdy.size(); j++) {
					if (results[j] != 0) {
						if (!isNumberRdy[j]) {
							hasNext = true;
						}
					}
				}
				if (!hasNext) {
					fill.append(1, '\n');
					break;
				}
				else {
					hasNext = false;
				}
			}
			else {
				fill.append(1, ' ');
				fill.append(1, ' ');
			}
		}
	}
	reversedLook.push_back(fill);
	reverse(reversedLook.begin(), reversedLook.end());
	string result;
	for (int i = 0; i < reversedLook.size(); i++) {
		result.append(reversedLook[i]);
	}
	return result;
}
int main() {
	vector<int> vec = { 9, 7, 8, 7, 10, 9 };
	histogram(vec);
}