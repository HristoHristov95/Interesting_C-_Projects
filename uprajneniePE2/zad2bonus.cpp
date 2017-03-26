#include<iostream>
using namespace std;
class pt1;
class pt2;
bool inuse(pt1,pt2);
class pt1 {
	int printing;
public:
	pt1() { printing = 0; }
	void set_print(int status) { printing = status; };
	friend bool inuse(pt1,pt2);
};
class pt2 {
	int printing;
public:
	pt2() { printing = 0; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pt1,pt2);
};
bool inuse(pt1 obj,pt2 obj1) {
	if (obj.printing || obj1.printing) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	pt1 obj;
	pt2 obj1;
	//obj.set_print(1);
	cout << boolalpha << inuse(obj,obj1) << endl;
	return 0;
}