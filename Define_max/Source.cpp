#include<iostream>
#include<ctime>
using namespace std;
#define MAX(a,b) (a>b ? a:b)
/*int Max(int* mStart, int nSize) {
	if (nSize == 1) { return *mStart; }
	*(mStart+1) = MAX(*mStart, *(mStart + 1));
	Max(mStart + 1, nSize - 1);
}*/
/*int Max(int* mStart, int nSize) {
	return nSize == 1 ? *mStart : MAX(*mStart, Max(mStart + 1, nSize - 1));
}*/
int Max(int* mStart, int nSize) {
	if (nSize == 1) {
		return *mStart;
	}
	else
	{
		//int number = Max(mStart + 1, nSize - 1);
		return MAX(*mStart, Max(mStart + 1, nSize - 1));
	}
}
int main() {
	int* arr=new int[1000];
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		arr[i] = rand()%10000;
	}
	clock_t t = clock();
	cout<<Max(arr, 1000)<<endl;
	cout << "Runtime is:  " << ((double)(clock() - t) / CLOCKS_PER_SEC) << endl;
	delete[] arr;
	return 0;
}