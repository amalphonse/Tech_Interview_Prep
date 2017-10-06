/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
-- simple version
*/

#include<iostream>

using namespace std;

int count(int S[], int m, int n) {
	int table[10];
	memset(table, 0, sizeof(table));

	table[0] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = S[i]; j < n; j++) {
			table[j] += table[j - S[i]];
		}
	}
	return table[n];
}

int main() {
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 4;
	cout << (arr, m, n) << endl;
	return 0;
	//Time complexity is O(mn).
}