//Print perimeter of a binary tree.

#include<iostream>

using namespace std;

/*
       20
	   /  \
	8      22
   / \      \
   4  12     25
      / \
    10  14

Boundary/Perimeter is: 20 8 4 10 14 25 22


*/

struct Node {
	int data;
	Node* left;
	Node* right;
};

void printLeaves(Node* root) {
	if (root) {
		printLeaves(root->left);
		if (!root->left && !root->right)
			cout << root->data << " ";
		printLeaves(root->right);
	}
}

void printLeftboundary(Node* root) {
	if (root) {
		if (root->left) {
			cout << root->data << " ";
			printLeftboundary(root->left);
		}else if(root->right){
			cout << root->data << " ";
			printLeftboundary(root->right);
		}
	}
}

void printRightboundary(Node* root) {
	if (root) {
		if (root->right) {
			printRightboundary(root->right);
			cout << root->data << " ";
		}
		else if (root->left) {
			printRightboundary(root->left);
			cout << root->data << " ";
		}
	}
}

void print_boundary(Node* root) {
	if (root) {
		cout << root->data << " ";
		printLeftboundary(root->left);
		printLeaves(root->left);
		printLeaves(root->right);
		printRightboundary(root->right);
	}
}

Node* new_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main() {
	Node* root = new_node(20);
	root->left = new_node(8);
	root->left->left = new_node(4);
	root->left->right = new_node(12);
	root->left->right->left = new_node(10);
	root->left->right->right = new_node(14);
	root->right = new_node(22);
	root->right->right = new_node(25);

	print_boundary(root);

	return 0;


}