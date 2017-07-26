#include<iostream>


using namespace std;

void islucky(int num) {
	int tmp;
	tmp = num;
	int count = 0;
	int sum1 = 0, sum2=0;
	while (tmp != 0) {
		while (count < 3) {
			sum1 += tmp % 10;
			tmp = tmp / 10;
			count++;
		}
		sum2 = sum1;
		cout << "Sum: " << "\n" << sum2 << endl;
		count = 0;
		sum1 = 0;
	}

}

string onceInATram(int x) {
	// Complete this function
}

int main() {

	int x;
	cin >> x;
	string result = onceInATram(x);
	cout << result << endl;
	islucky(165903);

	return 0;
}