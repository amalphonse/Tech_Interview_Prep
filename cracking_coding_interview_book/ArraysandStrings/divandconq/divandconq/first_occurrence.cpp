#include<iostream>

using namespace std;

int first_occurrence(int arr[], int len, int num) {
	int low = 0, high = len - 1;
	int result;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == num) {
			result = mid;
			high = mid - 1;
		}
		else if (num < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}

int last_occurrence(int arr[], int len, int num) {
	int low = 0, high = len - 1;
	int result;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == num) {
			result = mid;
			low = mid + 1;
		}
		else if (num < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return result;
}
int main() {
	int A[] = { 2,3,5,5,6,6,8,9,9,9,9 };
	int len = sizeof(A) / sizeof(A[0]);

	int index_fo = first_occurrence(A, len, 5);
	int index_lo = last_occurrence(A, len, 9);
	cout << "The first occurrence is: " << index_fo << endl;
	cout << "The last occurrence is: " << index_lo << endl;

	return 0;
}