//Reverse a singly linked list.
#include<iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* new_node(int data) {
	Node* node = NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

struct Node* insert_at_tail(Node* head, int data) {
	if (head == NULL)
		head = new_node(data);
	Node *current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node(data);
	return head;
}

void print(Node* head) {
	if (head == NULL)
		return;
	Node* current = head;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}

int main() {
	Node *head = NULL;
	insert_at_tail(head, 5);
	insert_at_tail(head, 10);
	print(head);

	return 0;
}