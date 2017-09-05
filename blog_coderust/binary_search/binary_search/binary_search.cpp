#include<iostream>

//Implement binary search on a sorted array.

using namespace std;

int binary_search(int arr[], int num, int len) {
	int mid, low, high;
	low = arr[0];
	high = arr[len - 1];
	mid = (low + high) / 2;

	if (arr[mid] == num) {
		return mid;
	}
	else if (num < arr[mid]) {
		high = mid - 1;
	}
	else {
		low = mid - 1;
	}

	return -1;
}
int main() {

	int a[] = {1,2,3,4,5,6};
	int size = sizeof(a) / sizeof(a[0]);
	cout << "Position of the number is: " << binary_search(a, 4, size) << endl;
	return 0;
}