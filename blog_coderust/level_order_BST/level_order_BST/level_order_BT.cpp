//Implement level order traversal of a binary tree.

#include<iostream>
#include<list>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void level_order(Node* root) {
	list<Node*> queue;
	Node* curr = NULL;
	queue.push_back(root);
	while (!queue.empty()) {

		curr = queue.front();
		queue.pop_front();
		cout << curr->data << " ";
		if (curr->left)
			queue.push_back(curr->left);
		if (curr->right)
			queue.push_back(curr->right);
	}
}

Node* new_node(int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

int main() {
	Node* root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	level_order(root);


	return 0;
}