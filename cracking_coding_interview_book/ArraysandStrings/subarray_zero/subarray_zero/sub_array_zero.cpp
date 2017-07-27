#include<iostream>
#include<unordered_set>

using namespace std;

bool zero_sum_aubarray(int arr[], int len) {
	unordered_set<int> s;

	s.insert(0);
	int sum = 0;

	for (int i = 0; i < len; i++) {
		sum = sum + arr[i];
		if (s.find(sum) != s.end()) {
			return true;
		}
		else {
			s.insert(sum);
		}
	}
	return false;
}

int main() {
	int A[] = { 4,2,-3,-1,0,4 };
	int n = sizeof(A) / sizeof(A[0]);

	zero_sum_aubarray(A, n) ? cout << "Zero Subarray exists." :
		cout << "Zero SubArray doesnt exists.";

	return 0;

}