#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class WhichAreIn
{

public:
	static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2) {
		int temp = 0;
		for (int i = 0; i < array1.size(); i++) {
			temp = 0;
			for(int k=0;k<array2.size();k++)
			{
				if ((array2[k].find(array1[i])) != -1) {
					temp = 1;
				}
			}
			if (temp == 0) {
				array1.erase(array1.begin()+i);
				i = -1;
			}
		}
		int check = 0;
		for (int i = 0; i < array1.size(); i++) {
			for (int j = i+1; j < array1.size(); j++){
				for (int k = 0; k < array1[i].length(); k++) {
					if (k <= (array1[j].length()-1)) {
						if (array1[i][k] > array1[j][k]) {
							std::string s = array1[i];
							array1[i] = array1[j];
							array1[j] = s;	
							check = 0;
							break;
						}
						else {
							if (array1[i][k] == array1[j][k])
							{
								check = j;
								continue;
							}
							else {
								break;
							}
						}
					}
				}
				if (check != 0) {
					if (array1[i].length() > array1[check].length()) {
						std::string s = array1[i];
						array1[i] = array1[check];
						array1[check] = s;
					}
				}
			}
		}
		return array1;
	}
};
int main() {
	WhichAreIn obj;
	vector<string> s = { "ar", "1295", "1028" };
	obj.inArray(s,s);
	return 0;
}