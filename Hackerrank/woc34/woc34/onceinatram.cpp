#include<iostream>
#include<string>


using namespace std;

bool islucky(int num) {
	/*int tmp;
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
		//cout << "Sum: " << "\n" << sum2 << endl;
		count = 0;
		sum1 = 0;
	}
	*/

	int arr[6];
	int sum_left = 0, sum_right = 0;
	int i = 0;
	int tmp;
	tmp = num;
	while (tmp != 0 && i<6) {
		arr[i] = tmp % 10;
		tmp = tmp / 10;
		i++;
	}

	sum_left = arr[0] + arr[1] + arr[2];
	sum_right = arr[3] + arr[4] + arr[5];
	if (sum_left == sum_right)
		return true;
	else
		return false;

}

string onceInATram(int x) {
	// Complete this function
	x = x + 1;
	while (!islucky(x)) {
		x = x + 1;
	}
	return to_string(x);
}

int main() {

	//int x;
	//cin >> x;
	string result = onceInATram(165903);
	cout << result << endl;
	//cout<<islucky();

	return 0;
}