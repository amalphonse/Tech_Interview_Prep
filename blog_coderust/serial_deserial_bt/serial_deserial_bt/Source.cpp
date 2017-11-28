/*
Serialize and Deserialize a binary tree.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#define MARKER -1

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* new_node(int data) {
	Node* node = new Node;
	node->left = node->right = NULL;
	return node;
}

void serialize(Node* root, string file_name) {
	ofstream fp;
	fp.open(file_name);
	if (!fp) {
		puts("Could not open file");
		return;
	}
	
		fp<< root->key;
		serialize(root->left, file_name);
		serialize(root->right, file_name);
	
}

/*void deserialize(Node* &root, ifstream fp) {
	int val;
	fp >> val;
	if (!fp || val == MARKER)
		return;
	root = new_node(val);
	deserialize(root->left,  fp);
	deserialize(root->right, fp);
}
*/

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		cout << root->key << endl;
		inorder(root->right);
	}
}

int main()
{
	// Let us construct a tree shown in the above figure
	string file_name = "tree.txt";
	//ifstream fp(file_name);
	struct Node *root = new_node(20);
	root->left = new_node(8);
	root->right = new_node(22);
	root->left->left = new_node(4);
	root->left->right = new_node(12);
	root->left->right->left = new_node(10);
	root->left->right->right = new_node(14);

	// Let us open a file and serialize the tree into the file
	/*fp.open("tree.txt");
	if (!fp)
	{
		puts("Could not open file");
		return 0;
	}*/
	serialize(root, file_name);
	

	// Let us deserialize the storeed tree into root1
	/*Node *root1 = NULL;
	fp = fopen_s("tree.txt", "r");
	deserialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from file:\n");
	inorder(root1);
	*/

	return 0;
}