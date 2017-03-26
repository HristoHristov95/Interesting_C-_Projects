#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*class CaesarCipher
{
public:
	static std::vector<std::string> movingShift(const std::string &s, int shift) {
		std::vector<std::string> results;
		std::string temp;
		long stringLenght = s.length();
		long currentCodeing = shift;
		int parts = 0;
		for (int i = 1;; i++) {
			double t = (double)((double)stringLenght / (double)i);
			if (t > 4 && t <= 5) {
				parts = i;
				break;
			}
		}
		for (int i = 0, m = parts; i < s.length(); i++, m--) {
			if (m == 0) {
				results.push_back(temp);
				temp.erase(temp.begin(), temp.end());
				m = parts;
			}
			if (isalpha(s[i])) {
				if (islower(s[i])) {
					if ((s[i] + currentCodeing) <= 122 && (s[i]+currentCodeing)>=97) {
						temp.append(1,s[i]+currentCodeing);
					}
					else {
						long temporary = currentCodeing + s[i];
						while (temporary > 122) {
							temporary -= 123;
							temporary += 97;
						}
						char x = (char)temporary;
						temp.append(1, x);
					}
				}
				else {
					if ((s[i] + currentCodeing) <= 90 && (s[i]+currentCodeing)>=65) {
						temp.append(1, s[i] + currentCodeing);
					}
					else {
						long temporary = currentCodeing + s[i];
						while (temporary > 90) {
							temporary -= 91;
							temporary += 65;
						}
						char x = (char)temporary;
						temp.append(1, x);
					}
				}
				currentCodeing++;
				continue;
			}
			temp.append(1, s[i]);
			currentCodeing++;
		}
		results.push_back(temp);
		return results;
	}
	static std::string demovingShift(std::vector<std::string> &s, int shift) {
		std::string result;
		long currentCodeing = shift;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].length(); j++) {
				if (isalpha(s[i][j])) {
					if (islower(s[i][j])) {
						if ((s[i][j] - currentCodeing) >= 97 && (s[i][j] - currentCodeing) <= 122) {
							result.append(1, s[i][j]-currentCodeing);
						}
						else {
							long temporary = s[i][j] - currentCodeing;
							while (temporary < 97) {
								temporary = 97 - temporary;
								temporary = 123 - temporary;
							}		
							char x = (char)temporary;
							result.append(1, x);
						}
					}
					else {
						if ((s[i][j] - currentCodeing) >= 65 && (s[i][j] - currentCodeing) <= 90) {
							result.append(1, s[i][j] - currentCodeing);
						}
						else {
							long temporary = s[i][j] - currentCodeing;
							while (temporary < 65) {
								temporary = 65 - temporary;
								temporary = 91 - temporary;
							}
							char x = (char)temporary;
							result.append(1, x);
						}
					}
				}
				else {
					result.append(1, s[i][j]);
				}
				currentCodeing++;
			}
		}
		return result;
	}
};
int main() {
	string s = "I should have known that you would have a perfect answer for me!!!";
	vector<string> k=CaesarCipher::movingShift(s, 1);
	cout<<CaesarCipher::demovingShift(k, 1).data()<<endl;
	return 0;
}*/