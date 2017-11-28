#include <iostream>
#include<vector>

using namespace std;
#define MAX 100

long getWays(long n, vector < long > c) {
	// Complete this function
	long m = c.size();
	long long int table[MAX][MAX];
	int x, y;

	for (int i = 0; i < m; i++)
		table[0][i] = 1;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 1; j <= m; j++) {
			x = (i - c[j]) > 0 ? table[i - c[j]][j] : 0;
			y = (j >= 1) ? table[i][j - 1] : 0;
			table[i][j] = x + y;
		}
	}

	return table[n][m-1];

}

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<long> c(m);
	for (int c_i = 0; c_i < m; c_i++) {
		cin >> c[c_i];
	}
	// Print the number of ways of making change for 'n' units using coins having the values given by 'c'
	long ways = getWays(n, c);
	cout << ways;
	return 0;
}
