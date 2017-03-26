#include<iostream>
#include<vector>
using namespace std;
std::string is_sorted_and_how(std::vector<int> array1)
{
	int ascending = 1;
	int descending = 1;
	for (int i = 0; i < array1.size()-1; i++) {
		if (descending) {
			if (array1[i] >= array1[i + 1]) {
				descending = 1;
			}
			else {
				descending = 0;
			}
		}
		if (ascending) {
			if (array1[i] <= array1[i + 1]) {
				ascending = 1;
			}
			else {
				ascending = 0;
			}
		}
	}
	if (ascending) {
		return "yes, ascending";
	}
	else if (descending){
		return "yes, descending";
	}
	else {
		return "no";
	}
}
int main() {
	vector<int> arr = { 1,12 };
	cout<< is_sorted_and_how(arr).data()<<endl;
	return 0;
}