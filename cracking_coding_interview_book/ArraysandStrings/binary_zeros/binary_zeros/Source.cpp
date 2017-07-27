#include<iostream>

using namespace std;

//Sorting a binary array with 0 and 1s.

void Sort_binary(int arr[], int len) {
	int zeros = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] == 0)
			zeros++;
	}
	int j = 0;
	while (zeros--) {
		arr[j] = 0;
		j++;
	}

	while (j < len) {
		arr[j++] = 1;
	}
	cout << "The array after sort: ";
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;

}
int main() {
	int A[] = { 0,0,1,0,1,1,0,1,0,0 };
	int size = sizeof(A) / sizeof(A[0]);
	cout << "The array before sort: " << endl;
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
	Sort_binary(A, size);
}