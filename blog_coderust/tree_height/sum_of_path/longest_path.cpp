#include<iostream>
#include<algorithm>
/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

*/

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int longest_path(Node* node, int &max_count) {
	if (node == NULL)
		return 0;
	int lval = longest_path(node->left, max_count);
	int rval = longest_path(node->right, max_count);

	int l_path = 0, r_path = 0;
	if (node->left && node->left->data == node->data)
		l_path = lval + 1;
	if (node->right && node->right->data == node->data)
		r_path = rval + 1;
	max_count = max(max_count, l_path + r_path);
	return max(l_path, r_path);
}

int Long_Uni_Val_Path(Node* node) {
	int max_count = 0;
	longest_path(node, max_count);
	return max_count;
}

Node* newNode(int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

int main() {
	Node *root = newNode(1);
	root->left = newNode(4);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(4);
	cout << Long_Uni_Val_Path(root);
	
}