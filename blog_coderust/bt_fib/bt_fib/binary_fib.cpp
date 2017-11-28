/*
Given a binary tree with nodes containing natural numbers. Assume
the numbers are 16 bit integers. Write a function that prints all the
nodes in the tree that are fibonacci numbers. The fibonacci sequence is
0,1,1,2,3,5,8,13,21,etc. The optimal solution should run in O(n) when
n is the number of nodes in a tree, with a one-time processing step of
O(k) where k is number of fibonacci numbers in a 16 bit integer. The
solution's order is unimportant.
Example: 1
/ \
3 7
/ \
4 6

prints: 1 3
*/

#include<iostream>

using namespace std;

int fib[100];
int len_fib;

//structure of the binary tree node
struct BTNode {
	int data;
	struct BTNode* left;
	struct BTNode* right;
};

void fib_series(int n) {
	int a = 0, b = 1;
	
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = a + b;
		a = b;
		b = fib[i];
	}

}

bool is_fib_num(int data) {
	
	for (int i = 0; i <= len_fib; i++) {
		if (data == fib[i])
			return true;
}
	return false;
}

void insert_bt(BTNode* head, int data) {

}


int main() {
	fib_series(10);
	len_fib = 10;
	for (int i = 0; i <= len_fib; i++) {
		cout << fib[i] << endl;
	}
}