//Merge two sorted linked lists.
#include<iostream>

using namespace std;

//recursive solution to merge linkedlist.
//In place.

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

Node* merge(Node* h1, Node* h2) {
	if (!h1) {
		return h2;
	}
	if (!h2)
		return h1;
	if (h1->data < h2->data) {
		h1->next = merge(h1->next, h2);
		return h1;
	}
	else {
		h2->next = merge(h1, h2->next);
		return h2;
	}

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

	Node* h2 = new_node(2);
	h2->next = new_node(4);

	Node *merged = merge(head, h2);

	print(merged);



	return 0;
}