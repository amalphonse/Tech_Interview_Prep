//using dynamic programming
#include<iostream>

using namespace std;

int number_of_paths(int r, int c) {
	int count[10][10];
	for (int i = 0; i < r; i++)
		count[i][0] = 1;
	for (int j = 0; j < c; j++)
		count[0][j] = 1;
	for (int i = 1; i < r; i++) {
		for (int j = 1;j < c; j++) {
			count[i][j] = count[i - 1][j] + count[i][j - 1];
		}
	}
	return count[r - 1][c - 1];
}

int main() {
	cout << number_of_paths(3, 3) << endl;
	return 0;
}