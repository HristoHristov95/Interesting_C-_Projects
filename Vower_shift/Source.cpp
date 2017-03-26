#include<iostream>
#include<vector>
#include<algorithm>

std::string vowelShift(std::string text, int n)
{
	std::vector<int> positions;
	std::vector<char> characters;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i]=='A' || text[i] == 'E' || text[i] =='I' || text[i] == 'O' || text[i] == 'U') {
			positions.push_back(i);
			characters.push_back(text[i]);
		}
	}
	std::vector<int>results;
	if (n > 0) {
		for (int i = 0; i < positions.size(); i++) {
			int number = n;
			int count = i;
			while (number != 0) {
				if (count == positions.size() - 1) {
					count = 0;
					number--;
					continue;
				}
				number--;
				count++;
			}
			results.push_back(count);
		}
	}
	else {
		for (int i = 0; i < positions.size(); i++) {
			int number = abs(n);
			int count = i;
			while (number != 0) {
				if (count == 0) {
					count = positions.size() - 1;
					number--;
					continue;
				}
				number--;
				count--;
			}
			results.push_back(count);
		}
	}
	std::vector<int> krai;
	int next = 0;
	for (int i = 0; i < results.size(); i++) {
		for (int j = 0; j < results.size(); j++) {
			if (results[j] == next) {
				krai.push_back(positions[j]);
				next++;
			}
		}
	}
	for (int i = 0; i < results.size(); i++) {
		for (int j = 0; j < results.size(); j++) {
			if (krai[i] == positions[j]) {
				text[positions[i]] = characters[j];
				break;
			}
		}
	}
	return text;
}
int main() {
	string s = "This is a test!";
	cout << vowelShift(s, 3).data() << endl;
	return 0;
}