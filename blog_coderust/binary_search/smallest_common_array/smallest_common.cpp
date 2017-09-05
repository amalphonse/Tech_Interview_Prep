//Find smallest common number in three sorted arrays.
#include<iostream>

using namespace std;

/*int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}*/

int smallest_common(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
	int i = 0, j = 0, k = 0,n=0;
	int min[5];

	while (i < n1 && j < n2 && k < n3) {
		if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
			min[n] = arr1[i];
			n++;
			i++; j++; k++;
		}
		if (arr1[i] < arr2[j]) {
			i++;
		}
		else if (arr2[j] < arr3[k]) {
			j++;
		}
		else {
			k++;
		}


	}
	int len = sizeof(min) / sizeof(min[0]);
	//qsort(min, len, sizeof(int), compare);

	//for (int i = 0; i < len; i++) {
	//	cout << min[i] << " ";
	//}

	return min[0];
	
}

int main() {

	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int ar2[] = { 6, 7, 20, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Element is ";
	cout<<smallest_common(ar1, ar2, ar3, n1, n2, n3)<<endl;

	return 0;
}