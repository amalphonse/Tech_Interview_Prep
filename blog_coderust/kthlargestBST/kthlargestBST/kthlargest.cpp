//Find nth highest number in a binary search tree.
#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* new_node(int data){
	Node* new_node = new Node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void kthlargestUtil(Node *root, int k, int &c) {
	if (root == NULL || c >= k)
		return;
	kthlargestUtil(root->right, k, c);
	c++;
	if (c == k) {
		cout << "Kth largest item is: " << root->data << endl;
		return;
	}
	kthlargestUtil(root->left, k, c);
}

void kthlargest(Node* root, int k) {
	int c = 0;
	kthlargestUtil(root, k, c);
}

Node* insert(Node* root, int key) {
	if (root == NULL)
		return new_node(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);
	return root;
}

int main()
{
	/* Let us create following BST
	50
	/     \
	30      70
	/  \    /  \
	20   40  60   80 */
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	int c = 0;
	for (int k = 1; k <= 7; k++)
		kthlargest(root, k);

	return 0;
}