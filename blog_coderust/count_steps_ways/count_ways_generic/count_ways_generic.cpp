#include<iostream>

using namespace std;

int count_ways(int steps, int ways) {
	if (steps <= 1)
		return steps;
	int result = 0;
	for (int i = 1; i <= steps && i <= ways; i++) {
		result += count_ways(steps - i, ways);
	}
	return result;
}

int main() {
	int s = 4;
	int m = 2;
	cout << "Number of ways to " << s << " steps= " << count_ways(s + 1, m) << endl;
	return 0;
}