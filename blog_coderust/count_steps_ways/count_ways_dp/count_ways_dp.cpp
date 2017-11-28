#include<iostream>

using namespace std;

int count_ways(int steps, int ways) {
	int result[100];
	result[0] = 1;
	result[1] = 1;
	for (int i = 2; i <= steps; i++) {
		result[i] = 0;
		for(int j=1;j<=i&&j<=ways;j++){
			result[i] += result[i - j];
		}
	}
	return result[steps - 1];
}

int main() {
	int s = 4;
	int m = 2;
	cout << "Number of ways of getting " << s << " steps is: " << count_ways(s + 1, m) << endl;
	return 0;
}