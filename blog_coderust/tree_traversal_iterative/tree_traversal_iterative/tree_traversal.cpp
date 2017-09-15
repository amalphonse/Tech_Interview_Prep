//Implement iterative in-order traversal of a binary tree.

#include<iostream>

using namespace std;

//Creating the tree_node and the stcack node structures.
struct tree_node {
	tree_node* left;
	tree_node* right;
	int data;
};

struct stack_node {
	tree_node* tn;
	stack_node* next;
};

//Push, Pop and isEmpty functions.

void push(stack_node** top_ref, tree_node* tnode) {

	stack_node* new_tn = new stack_node;
	if (new_tn == NULL) {
		cout << "Stack Overflow." << endl;
	}

	new_tn->tn = tnode;
	new_tn->next = (*top_ref);

	(*top_ref) = new_tn;

}

bool isEmpty(stack_node* top) {

	return (top == NULL) ? 1 : 0;
}

tree_node* pop(stack_node** top_ref) {
	tree_node* res;
	stack_node* top;

	if (isEmpty(*top_ref)) {
		cout << "Stack Overflow.." << endl;
	}
	else {
		top = *top_ref;
		res = top->tn;
		*top_ref = top->next;
		delete(top);
		return res;
	}
}

tree_node* newtNode(int data) {
	tree_node* tNode = new tree_node;
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

//Inorder traversal.
void inOrder(tree_node* root) {

	tree_node* current = root;
	stack_node* snode = NULL;
	bool done = false;

	while (!done) {
		if (current != NULL) {
			push(&snode, current);
			current = current->left;
		}
		else {
			if (!isEmpty(snode)) {
				current = pop(&snode);
				cout << current->data << endl;
				current = current->right;
			}
			else {
				done = true;
			}
		}
	}
}

int main()
{

	/* Constructed binary tree is
	1
	/   \
	2      3
	/  \
	4     5
	*/
	tree_node *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	inOrder(root);

	getchar();
	return 0;
}