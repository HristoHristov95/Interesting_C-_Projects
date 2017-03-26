#include<iostream>
#include<vector>
class SqInRect
{
public:
	static std::vector<int> sqInRect(int lng, int wdth) {
		long total = lng*wdth;
		std::vector<int> vec;
		if (lng != wdth) {
			for (long i = total; i > 0; i--) {
				if (((i*i) <= total) && (i <= lng && i <= wdth)) {
					vec.push_back(i);
					total -= (i*i);
					if (i == lng) {
						wdth = wdth - i;
					}
					if (i == wdth) {
						lng = lng - i;
					}
					i = total;
				}
			}
			if (total != 0) {
				vec.push_back(sqrt(total));
			}
		}
		return vec;
	}
};
int main() {
	SqInRect obj;
	std::vector<int> a= obj.sqInRect(5, 3);
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}
	return 0;
}