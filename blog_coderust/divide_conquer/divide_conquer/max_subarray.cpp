//Find sub-array with largest sum in an integer array.

//You are given a one dimensional array that may contain both positive and negative integers, 
//find the sum of contiguous subarray of numbers which has the largest sum.

#include<iostream>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h) {
	int sum = 0;
	int left_max = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_max)
			left_max = sum;
	}
	sum = 0;
	int right_max = INT_MIN;
	for (int i = m+1; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_max)
			right_max = sum;
	}
	return left_max + right_max;
}

int maxSubArray(int arr[], int l, int h) {
	if (l = h)
		return arr[l];
	int m = (l + h) / 2;
	return (max(maxSubArray(arr, l, m), maxSubArray(arr, m + 1, h), maxCrossingSum(arr, l, m, h)));
}

int main() {
	int arr[] = { 2, 3, 4, 5, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max_sum = maxSubArray(arr, 0, n - 1);
	cout<<"Maximum contiguous sum is: "<< max_sum<<endl;
	//getchar();
	return 0;

	return 0;
}