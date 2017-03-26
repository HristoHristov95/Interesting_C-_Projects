#include<iostream>
#include<algorithm>
using namespace std;
class MyClass {
public:
	int array1[9] = { 3,7,8,5,2,1,9,6,4 };
};
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*int calculate(MyClass& object, int first, int last) {
	int main_value = object.array1[last];
	int swapValue = first - 1;
	for (int i = first; i <= last; i++) {
		if (object.array1[i] <= main_value) {
			swapValue++;
			swap(object.array1[i], object.array1[swapValue]);
		}
	}
	return swapValue;
}
void quick_sort(MyClass& object, int first, int last) {
	if (first < last) {
		int newIndex = calculate(object, first, last);
		quick_sort(object, first, last - 1);
		quick_sort(object, first + 1, last);
	}
}*/
/*void calculate(MyClass& object, int maxCount, int currentBiggestLeft) {
	int largest = currentBiggestLeft;
	int l = currentBiggestLeft * 2 + 1;
	int r = currentBiggestLeft * 2 + 2;
	if (l<maxCount && object.array1[l]>object.array1[largest]) {
		largest = l;
	}
	if (r<maxCount && object.array1[r]>object.array1[largest]) {
		largest = r;
	}
	if (currentBiggestLeft != largest) {
		swap(object.array1[currentBiggestLeft], object.array1[largest]);
		calculate(object, maxCount, largest);
	}

}
void heap_sort(MyClass& object, int maxCount) {
	for (int i = maxCount / 2-1; i >= 0; i--) {
		calculate(object, maxCount, i);
	}
	for (int i = maxCount - 1; i >= 0; i--) {
		swap(object.array1[0], object.array1[i]);
		calculate(object, i, 0);
	}
}*/
int calculate(int arr[], int n) {
	int maximum = 0;
	int* arr1 = new int[n];
	memcpy(arr1, arr, n * sizeof(int));
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && arr1[i] < arr[i] + arr1[j]) {
				arr1[i] = arr[i] + arr1[j];
				maximum = max(maximum, arr1[i]);
			}
		}
	}
	return maximum;
}
int main() {
	MyClass object;
//	quick_sort(object, 0, 9 - 1);
	heap_sort(object, 9);
	for (int i = 0; i < 9; i++) {
		cout << object.array1[i] << " ";
	}
	return 0;
}