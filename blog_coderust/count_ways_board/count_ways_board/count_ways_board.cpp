/*
Count all possible paths from top left to bottom right of a mXn matrix
The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down
*/

#include<iostream>

using namespace std;

int number_of_paths(int r, int c) {
	if (r == 1 || c == 1)
		return 1;
	return number_of_paths(r - 1, c) + number_of_paths(r, c - 1);
}

int main() {
	cout << number_of_paths(3, 3) << endl;
	return 0;
}