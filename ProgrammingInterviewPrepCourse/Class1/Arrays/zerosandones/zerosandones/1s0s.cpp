#include<iostream>

using namespace std;

void swap(int *a, int *b) {
	int *t;
	t = a;
	a = b;
	b = t;
}

void rearrange(int *a, int n) {
	int i = 0, j = n - 1;
	while (i <= j) {
	if (a[i] == 0) {

		i++;
	}
	else if (a[j] == 1) {

		j--;
	}
	else {
		//swap(&a[i], &a[j]);
		int t;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}
}

int main() {

	int a[] = { 0,1,1,0,1 };
	int n = 5;
	rearrange(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return 0;
}