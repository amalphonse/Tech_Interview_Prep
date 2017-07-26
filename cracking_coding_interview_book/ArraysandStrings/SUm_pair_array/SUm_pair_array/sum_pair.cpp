#include<iostream>
#include<map>

using namespace std;

/*Question: Given an unsorted array find a pair with given sum in it.
The hashing approach take O(n), because it goes over all the element
in the array once.*/

void find_pair(int arr[], int len, int sum) {
	map<int, int> m;
	for (int i = 0; i < len; i++) {
		if (m.find(sum - arr[i]) != m.end()) {
			cout << "Pair found at index " << m[sum - arr[i]] << " at index " <<
				i << endl;
			return;
		}
		m[arr[i]] = i;
	}
	cout << "Pair not found." << endl;
}

int main() {
	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;

	int l = sizeof(arr) / sizeof(arr[0]);

	find_pair(arr, l, sum);

	return 0;
}