#include<iostream>
#include<vector>

class Kata
{
public:
	std::vector<int> sortArray(std::vector<int> array1)
	{
		if (array1.size() != 0) {
			for (long k = 0; k < array1.size(); k++) {
				for (long i = k+1; i < array1.size(); i++) {
					if (((array1[k] % 2) != 0)) {
						if (((array1[i]) % 2 != 0)) {
							if (array1[k] > array1[i]) {
								int temp = array1[k];
								array1[k] = array1[i];
								array1[i] = temp;
							}
						}
					}
					else {
						break;
					}
				}
			}
			return array1;
		}
		else {
			return array1;
		}
	}
};
int main() {
	vector<int> a = { 5,3,2,8,1,4 };
	Kata obj;
	a=obj.sortArray(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}