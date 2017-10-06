#include<iostream>
#include<algorithm>

using namespace std;

/*
Check Tree is Balanced:
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a 
tree such that the heights of the two subtrees of any node never differ by more than one.
*/

struct Node {
	int data;
	Node* left;
	Node* right;
};

int height(Node* node) {
	if (node == NULL)
		return -1;
	return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(Node* node) {
	if (node == NULL)
		return false;
	int rheight = height(node->right);
	int lheight = height(node->left);

	if (abs(lheight - rheight) > 1 && isBalanced(node->left) && isBalanced(node->right))
		return true;
	return false;
}

Node* newNode(int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

int main() {
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(8);

	if (isBalanced(root))
		printf("Tree is balanced");
	else
		printf("Tree is not balanced");

	getchar();
	return 0;
}