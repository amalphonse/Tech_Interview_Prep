#include<iostream>

using namespace std;

int binary_search(int A[], int len, int num) {
	int low = 0;
	int high = len - 1;
	
	int result;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == num)
			return mid;
		else if (num < A[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}
	return -1;
}

int main() {
	
		int A[] = { 1,2,5,7,8,9 };
		int len = sizeof(A) / sizeof(A[0]);
		int index_occurrence = binary_search(A, len, 7);

		if (index_occurrence == -1) {
			cout << "The element doesnt exist" << endl;
		}
		else {

			cout << "The occurrence is: " << index_occurrence << endl;

		}
		return 0;
	
}
