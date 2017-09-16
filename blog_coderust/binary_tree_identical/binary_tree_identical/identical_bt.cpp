//Validate if two binary trees are identical.
#include<iostream>
#include<queue>

using namespace std;

//structure of the node
struct Node {
	int data;
	Node* left;
	Node* right;
};

bool areIdentical(Node* root1, Node* root2) {
	queue<Node*> q1, q2;

	if (!root1 && !root2)
		return true;
	if (!root1 || !root2)
		return false;

	q1.push(root1);
	q2.push(root2);

	while (!q1.empty() && !q2.empty()) {

		Node* n1 = q1.front();
		Node* n2 = q2.front();

		if (n1->data != n2->data) {
			return false;
		}

		q1.pop();
		q2.pop();

		if (n1->left && n2->left) {
			q1.push(n1->left);
			q2.push(n2->left);
		}
		else if (n1->left || n2->left)
			return false;

		if (n1->right && n2->right) {
			q1.push(n1->right);
			q2.push(n2->right);
		}
		else if (n1->right || n2->right)
			return false;
	}
	return true;
}

Node* new_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main() {

	Node *root1 = new_node(1);
	root1->left = new_node(2);
	root1->right = new_node(3);
	root1->left->left = new_node(4);
	root1->left->right = new_node(5);

	Node *root2 = new_node(1);
	root2->left = new_node(2);
	root2->right = new_node(3);
	root2->left->left = new_node(4);
	root2->left->right = new_node(5);

	areIdentical(root1, root2) ? cout << "Yes"
		: cout << "No";
	return 0;

	return 0;
}

