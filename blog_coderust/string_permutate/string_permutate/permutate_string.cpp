//Find all permutations of a given string.
#include<iostream>

using namespace std;

void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutate(char *a, int l, int r) {
	int i;
	if (l == r)
		cout << a << endl;
	else {
		for (int i = l; i <= r; i++) {
			swap((a + l), (a + i));
			
			permutate(a, l + 1, r);
			
			swap((a + l), (a + i));
			
		}
	}
}

int main() {
	char str[] = "DEF";
	int n = strlen(str);
	permutate(str, 0, n - 1);

	return 0;
}