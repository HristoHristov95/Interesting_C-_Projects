#include<iostream>
#include<array>
#include<set>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<iterator>
using namespace std;
int main() {
	list<string> lis1 = { "Hello","my","friend!" };
	list<string> lis2;
	vector<int> vec1 = {7,8,9,10};
	vector<int> vec2;
	set<int> set1 = {15,16,17,18,19};
	set<int> set2;
	map<string, int> map1 = {make_pair("Hello",1),make_pair("friend",123)};
	map<string, int> map2;
	copy(lis1.begin(), lis1.end(), inserter(lis2,lis2.begin()));
	copy(vec1.begin(), vec1.end(), inserter(vec2, vec2.begin()));
	list<string>::iterator lis2Iter = lis2.begin();
	for (int i = 0; i < lis2.size(); i++) {
		cout << lis2Iter++->data() << endl;
	}
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << endl;
	}
	return 0;
}