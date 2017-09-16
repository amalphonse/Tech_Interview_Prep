//Recuresive identical BT
#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* new_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool areIdentical(Node* root1, Node* root2) {
	if (!root1 && !root2)
		return true;

	if (root1 != NULL && root2 != NULL) {
		return (root1->data == root2->data && areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right));
	}
	return false;
}

int main() {
	Node *root1 = new_node(1);
	root1->left = new_node(2);
	root1->right = new_node(3);
	//root1->left->left = new_node(4);
	//root1->left->right = new_node(5);

	Node *root2 = new_node(1);
	root2->left = new_node(2);
	root2->right = new_node(3);
	root2->left->left = new_node(4);
	root2->left->right = new_node(5);

	areIdentical(root1, root2) ? cout << "Yes"
		: cout << "No";
	return 0;
}