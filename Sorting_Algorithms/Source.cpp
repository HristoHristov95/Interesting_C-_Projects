#include<iostream>
#include<vector>
using namespace std;
class MyTest {
public:
	int array1[9] = { 3,9,8,5,2,1,7,6,4 };
};
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*int partition(MyTest& object, int first, int last) {
	int pivotValue = object.array1[last];
	int i = first - 1;
	for (int j = first; j <= last - 1; j++) {
		if (object.array1[j] <= pivotValue) {
			i++;
			swap(object.array1[j], object.array1[i]);
		}
	}
	swap(object.array1[i + 1], object.array1[last]);
	return i+1;
}
void quickSort(MyTest& object,int first,int last) {
	if (first < last) {
		int newPivotIndex = partition(object, first, last);
		quickSort(object, first,newPivotIndex - 1);
		quickSort(object, newPivotIndex + 1, last);
	}
}*/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(MyTest& object, int maxSizeOfArray, int indexOfBiggestElement)
{
	int largest = indexOfBiggestElement;  // Initialize largest as root
	int l = 2 * indexOfBiggestElement + 1;  // left = 2*i + 1
	int r = 2 * indexOfBiggestElement + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < maxSizeOfArray && object.array1[l] > object.array1[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < maxSizeOfArray && object.array1[r] > object.array1[largest])
		largest = r;

	// If largest is not root
	if (largest != indexOfBiggestElement)
	{
		swap(object.array1[indexOfBiggestElement], object.array1[largest]);

		// Recursively heapify the affected sub-tree
		heapify(object, maxSizeOfArray, largest);
	}
}

// main function to do heap sort
void heapSort(MyTest& object, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(object, n, i); //nemoje samo 1 put da se izvika za6toto purviq put trqbva caliq masiv da se pretursi za nai golemniq element

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(object.array1[0], object.array1[i]);

		// call max heapify on the reduced heap
		heapify(object, i, 0); // i елемента защото i става -1 на всяко връщане тоест маx брой на елементи които трябва да се сортират намалява
	}
}
int main() {
	MyTest object;
	heapSort(object, 9);
	//quickSort(object, 0, 9 - 1);
	for (int i = 0; i < 9; i++) {
		cout << object.array1[i] << " ";
	}
}