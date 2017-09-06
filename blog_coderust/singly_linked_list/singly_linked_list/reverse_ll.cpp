//Reverse a singly linked list.
#include<iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* new_node(int data) {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

struct Node* insert_at_tail(Node** head, int data) {
	
	if (*head == NULL){
		*head = new_node(data);
	}
	Node *current = *head;
	while (current->next != NULL) {
		cout << current->data << "inside while loop." << endl;
		current = current->next;
	}
	current->next = new_node(data);
	return *head;
}

void print(Node** head) {
	if (*head == NULL)
		return;
	Node* current = *head;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}

Node* reverse(Node** head) {

	Node* prev = NULL;
	Node* current = *head;
	Node* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return *head;
}

int main() {
	Node *head = NULL;
	insert_at_tail(&head, 5);
	insert_at_tail(&head, 10);
	insert_at_tail(&head, 20);
	insert_at_tail(&head, 25);
	insert_at_tail(&head, 30);
	insert_at_tail(&head, 35);
	cout << "The list before the reverse: " << endl;
	print(&head);
	reverse(&head);
	cout << "The list after reverse: " << endl;
	print(&head);

	return 0;
}