/*
Count ways to reach the n’th stair. With recursion 
*/
#include<iostream>

using namespace std;

int count_ways(int n) {
	if (n <= 1)
		return n;
	return count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3);
}

int main() {
	int n = 4;
	cout << "The number of ways to 4 steps is: " << count_ways(n + 1) << endl;

	return 0;
}