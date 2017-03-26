#include<iostream>
#include<algorithm>
using namespace std;
/* maxSumIS() returns the maximum sum of increasing subsequence
in arr[] of size n */
int maxSumIS(int arr[],int n)
{
	int maximum = 0;
	int msis[7];

	/* Initialize msis values for all indexes */
	memcpy(msis, arr,sizeof(arr)*n);
	/* Compute maximum sum values in bottom up manner */
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
				msis[i] = msis[j] + arr[i];
				/* Pick maximum of all msis values */
				maximum = max(maximum, msis[i]);
			}
		}
	}
	return maximum;
}
/*
Дадено ви е поле с 1 ≤ N ≤ 30 реда и 1 ≤ M ≤ 30 колони. Започвайки от горния ляв ъгъл, по колко начина можете да стигнете до долния десен такъв, движейки се само надолу или надясно?
Например при поле с три реда и три колони има шест такива пътя: { (надясно, надясно, надолу, надолу), (надясно, надолу, надясно, надолу), (надясно, надолу, надолу, надясно), (надолу, надясно, надясно, надолу), (надолу, надясно, надолу, надясно), (надолу, надолу, надясно, надясно) }.


long long recursive(int remRows,int remCols){
if(remRows==0 || remCols==0){
return 1;
}
if(dyn[remRows][remCols] != 1){
return dyn[remRows][remCols];
}
long long ans=0;
ans+=recursive(remRows-1,remCols);
ans+=recursive(remRows,remCols-1);
return dyn[remRows][remCols]=ans;
}

*/
int main()
{
	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSumIS(arr, n) << endl;
	return 0;
}