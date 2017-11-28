/*
Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. She is biased towards her friends and may have distributed the chocolates unequally. One of the program managers gets to know this and orders Christy to make sure everyone gets equal number of chocolates.

But to make things difficult for the intern, she is ordered to equalize the number of chocolates for every colleague in the following manner,

For every operation, she can choose one of her colleagues and can do one of the three things.

She can give one chocolate to every colleague other than chosen one.
She can give two chocolates to every colleague other than chosen one.
She can give five chocolates to every colleague other than chosen one.
Calculate minimum number of such operations needed to ensure that every colleague has the same number of chocolates. 
*/
#include<iostream>
#include<vector>

using namespace std;

int ops(int rem) {
	int op = 0;
	op += rem / 5;
	rem %= 5;
	op += rem / 2;
	rem %= 2;
	op += rem;
	return op;
}

int main() {
	int min = INT_MAX;
	int n = 4;
	vector<int> v(n);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);
	for (int i = 0; i < n; i++) {
		
		if (v[i] < min) {
			min = v[i];
		}
	}
	int answer = INT_MAX;
	for (int i = 0; i < 4; i++) {
		int temp_answer = 0;
		for (int j = 0; j < n; j++) {
			temp_answer += ops(v[j] - min + i);
		}
		if (temp_answer < answer)
			answer = temp_answer;
	}
	cout << answer << endl;

}