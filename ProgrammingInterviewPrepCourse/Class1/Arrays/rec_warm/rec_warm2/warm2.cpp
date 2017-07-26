#include<iostream>

using namespace std;



void fun(int n) {
	cout << "n = " << n << endl;

	if (n == 0) return;

	for (int i = 0; i< n; i++) {

		fun(n - 1);

	}
	//cout << "n = " << n << endl;

}

int main() {
	fun(3);
	return 0;
}