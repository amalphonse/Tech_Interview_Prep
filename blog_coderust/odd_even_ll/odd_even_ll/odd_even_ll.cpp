/*
Rearrange the given linked list such that every even node will be moved to the end of the list in reverse 
order.

Input: 1->2->3->4->5->6->7->null
Output: 1->3->5->7->6->->4->2->null
*/
#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void print(Node* head) {
	Node* ptr = head;
	while (ptr) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
void add_node(Node** head, int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void Move_Node(Node** dest, Node** src) {
	if(*src == NULL) {
		return;
	}
	Node* new_node = *src;
	*src = (*src)->next;
	new_node->next = *dest;
	*dest = new_node;
}

void rearrange(Node* head) {
	if (head == NULL)
		return;
	Node* odd = head;
	Node* even = NULL;
	Node* prev = NULL;

	while (odd && odd->next) {
		Move_Node(&even, &(odd->next));
		prev = odd;
		odd = odd->next;
	}
	if (odd)
		odd->next = even;
	else
		prev->next = even;
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7 };
	int len = sizeof(arr) / sizeof(arr[0]);

	Node* head = NULL;
	for (int i = len - 1; i >= 0; i--)
		add_node(&head, arr[i]);
	cout << "Before rearranging: " << endl;
	print(head);
	rearrange(head);
	cout << "After rearranging: " << endl;
	print(head);
	return 0;
}