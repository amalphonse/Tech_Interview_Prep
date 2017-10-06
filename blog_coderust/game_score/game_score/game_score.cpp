/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of ways to reach the given score.
dynamic programming
*/
#include<iostream>

using namespace std;

int score_count(int score) {
	int table[30], i;
	memset(table, 0, sizeof(table));
	table[0] = 1;
	for (i = 3; i <= score; i++)
		table[i] += table[i - 3];
	for (i = 5; i <= score; i++)
		table[i] += table[i - 5];
	for (i = 10; i <= score; i++)
		table[i] += table[i - 10];

	return table[score];
}

int main() {
	int n = 20;
	cout << "Number of ways to get score " << n <<" "<< score_count(n);
	return 0;
}