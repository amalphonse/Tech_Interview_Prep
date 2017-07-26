#include<iostream>

using namespace std;

void max_heapify(int arr[], int i, int heap_size) {
	int largest = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;

	if (l<heap_size && arr[l]>arr[largest]) {
		largest = l;
	}
	if (r<heap_size && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		max_heapify(arr,largest,heap_size);
	}
}

void heap_sort(int *arr, int n) {
	//First build the array
	for (int i = n / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, n);
	}

	//heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver program
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heap_sort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}