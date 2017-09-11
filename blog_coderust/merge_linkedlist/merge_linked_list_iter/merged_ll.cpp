//Merge two sorted linked lists.
//Iterative approach
#include<iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* new_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;

	return node;
}

Node* MergeUtil(Node* h1, Node* h2) {
	if (!h1->next) {
		h1->next = h2;
		return h1;
	}

	Node* curr1 = h1;
	Node* curr2 = h2;

	Node* next1 = h1->next;
	Node *next2 = h2->next;
	while (next1 && next2)
	{


		if (curr1->data < curr2->data &&
			curr2->data < next1->data) {
			next2 = curr2->next;
			curr1->next = curr2;
			curr2->next = next1;

			curr1 = curr2;
			curr2 = next2;
		}
		else {
			if (next1->next) {
				next1 = next1->next;
				curr1 = curr1->next;
			}
			else {
				next1->next = curr2;
				return h1;
			}
		}
	}
	return h1;
}

Node* merge(Node* h1, Node* h2) {
	if (!h1) {
		return h1;
	}
	if (!h2) {
		return h1;
	}

	if (h1->data < h2->data)
		return MergeUtil(h1, h2);
	else
		return MergeUtil(h2, h1);
}

void print(Node* node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main() {
	Node* head = new_node(1);
	head->next = new_node(3);
	head->next->next = new_node(5);
	//Linkded List 1 created

	Node* h2 = new_node(0);
	h2->next = new_node(2);
	h2->next->next = new_node(4);

	Node *merged = merge(head, h2);

	print(merged);


	return 0;
}