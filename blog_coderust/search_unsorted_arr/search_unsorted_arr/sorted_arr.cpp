//Find an element in a rotated array that was originally sorted.
#include<iostream>

using namespace std;

int Search(int arr[], int low, int high, int key) {
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (key == arr[mid])
		return mid;
	//low to mid is sorted then binary search on the 2 parts.
	if (arr[low] <= arr[mid]) {
		if (key >= arr[low] && key <= arr[mid])
			return Search(arr, low, mid - 1, key);
		return Search(arr, mid + 1, high, key);
		}
	//When mid to high is sorted
	if (key >= arr[mid] && key <= arr[high])
		return Search(arr, mid + 1, high, key);
	return Search(arr, low, mid - 1, key);
}

int main() {
	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 6;
	int i = Search(arr, 0, n - 1, key);
	if (i != -1) cout << "Index: " << i << endl;
	else cout << "Key Not Found"<<endl;

	return 0;
}