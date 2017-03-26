#include<iostream>
#include<vector>
int stray(std::vector<int> numbers) {
	int same = 0;
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[0] == numbers[i]) {
			same = numbers[i];
			break;
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] != same) {
			return numbers[i];
		}
	}
	return 0;
};