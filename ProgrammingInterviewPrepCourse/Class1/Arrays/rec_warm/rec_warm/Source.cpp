#include<iostream>


using namespace std;

void function(int n) {
	if (n > 5)
		return;
	function(n + 1);
	cout << "n = " << n << endl;
	//return m + 1;
}

int main() {
	//cout<<"n+1 ="<<function(1)<<endl;
	function(2);
	return 0;
}