#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class CaesarCipher
{
public:
	static std::vector<std::string> movingShift(const std::string &s, int shift) {
		std::vector<std::string> results;
		std::vector<char> lowerCase = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		std::vector<char> upperCase = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		int parts;
		std::string temp;
		int counter = shift;
		int m = ceil((double)s.length() / 5);
		parts = m;
		for (int i = 0; i < s.length(); i++,m--) {
			if (m == 0) {
				results.push_back(temp);
				temp.erase(temp.begin(), temp.end());
				m = parts;
			}
			if (isalpha(s[i])) {
				if (islower(s[i])) {
					int position = find(lowerCase.begin(), lowerCase.end(), s[i]) - lowerCase.begin();
					position = position + counter;
					if (position>25) {
						while (position > 25) {
							position -= 26;
						}
					}
					temp.append(1, lowerCase[position]);
				}
				else {
					int position = find(upperCase.begin(), upperCase.end(), s[i]) - upperCase.begin();
					position = position + counter;
					if (position > 25) {
						while (position > 25) {
							position -= 26;
						}
					}
					temp.append(1, upperCase[position]);
				}
			}
			else {
				temp.append(1, s[i]);
			}
			counter++;
		}
		results.push_back(temp);
		temp.erase(temp.begin(), temp.end());
		if (results.size() != 5) {
			results.push_back(temp);
		}
		return results;
	}
	static std::string demovingShift(std::vector<std::string> &s, int shift) {
		std::string results;
		std::vector<char> lowerCase = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		std::vector<char> upperCase = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].length(); j++) {
				if (isalpha(s[i][j])) {
					if (islower(s[i][j])) {
						int position = find(lowerCase.begin(), lowerCase.end(), s[i][j]) - lowerCase.begin();
						int c = 0;
						while (c < shift) {
							c++;
							position--;
							if (position < 0) {
								position = 25;
							}
						}
						results.append(1, lowerCase[position]);
					}
					else {
						int position = find(upperCase.begin(), upperCase.end(), s[i][j]) - upperCase.begin();
						int c = 0;
						while (c < shift) {
							c++;
							position--;
							if (position < 0) {
								position = 25;
							}
						}
						results.append(1, upperCase[position]);
					}
				}
				else {
					results.append(1, s[i][j]);
				}
				shift++;
			}
		}
		return results;
	}
};
int main() {
	string s = "I should have known that you, would have a , perfect answer for me!!!";
	vector<string> s1=CaesarCipher::movingShift(s, 1);
	cout<<CaesarCipher::demovingShift(s1, 1);
	return 0;
}