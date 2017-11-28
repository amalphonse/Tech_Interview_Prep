/*
Wildcard Pattern Matching
Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text (not partial text).

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character

‘*’ – Matches any sequence of characters (including the empty sequence)
*/
#include<iostream>

using namespace std;

bool pattern_match(char str[], char pattern[], int sl, int pl) {

	if (sl == 0)
		return (pl == 0);
	bool lookup[15][15];

	memset(lookup, false, sizeof(lookup));

	//pattern and text null
	lookup[0][0] = true;

	for (int i = 1; i <= pl; i++) {
		if (pattern[i - 1] == '*')
			lookup[0][i] = lookup[0][i - 1];
	}

	//fill the table bottom up fashion
	for (int i = 1; i <= sl; i++) {
		for (int j = 1; j <= pl; j++) {
			if (pattern[j - 1] == '*') {
				lookup[i][j] = lookup[i - 1][j] ||
					lookup[i][j - 1];
			}
			else if (pattern[j - 1] == '?' ||
				pattern[j - 1] == str[i - 1]) {
				lookup[i][j] = lookup[i - 1][j - 1];
			}
			else {
				lookup[i][j] = lookup[i - 1][j - 1];
			}
		}
	}
		return lookup[sl][pl];

	
}

int main()
	{
		char str[] = "baaabab";
		char pattern[] = "*****ba*****ab";
		// char pattern[] = "ba*****ab";
		// char pattern[] = "ba*ab";
		// char pattern[] = "a*ab";
		// char pattern[] = "a*****ab";
		// char pattern[] = "*a*****ab";
		// char pattern[] = "ba*ab****";
		// char pattern[] = "****";
		// char pattern[] = "*";
		// char pattern[] = "aa?ab";
		// char pattern[] = "b*b";
		// char pattern[] = "a*a";
		// char pattern[] = "baaabab";
		// char pattern[] = "?baaabab";
		// char pattern[] = "*baaaba*";

		if (pattern_match(str, pattern, strlen(str),
			strlen(pattern)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		return 0;
	}