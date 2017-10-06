/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
dynamic programming.
*/

#include<iostream>
#define L 10
using namespace std;

int count(int S[], int n, int m) {
	int table[L][L];
	int x, y;
	//fill the 0th row with 1 for the 0 coins
	for (int i = 0; i < m; i++)
		table[0][i] = 1;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			//INcluding jth coin
			x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
			//Excluding jth coin
			y = (j >= 1) ? table[i][j - 1] : 0;
			table[i][j] = x + y;
		}
	}
	return table[n + 1][m];
}
int main() {
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 4;
	cout<<(arr, m, n)<<endl;
	return 0;
	//Time complexity is O(mn).
}