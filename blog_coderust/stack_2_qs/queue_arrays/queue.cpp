//Implementing a queue with array

#include<iostream>

using namespace std;

//structure of queue
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* arr;
};

Queue* create_queue(unsigned capacity) {
	Queue* q = new Queue;
	q->capacity = capacity;
	q->front = 0;
	q->size = 0;
	q->rear = capacity - 1;
	q->arr = (int*) malloc(q->capacity * sizeof(int));
	return q;
}

bool isFull(Queue* q) {
	return (q->size == q->capacity);
}

bool isEmpty(Queue* q) {
	return (q->size == 0);
}

void enqueue(Queue* q, int data) {
	if (isFull(q))
		return;
	q->rear = (q->rear + 1)%q->capacity;
	q->arr[q->rear] = data;
	q->size = q->size + 1;
	cout << "Enqueued to queue" << endl;
}

int dequeue(Queue* q) {
	if (isEmpty(q))
		return INT_MIN;
	int data = q->arr[q->front];
	q->front = q->front%q->capacity;
	q->size = q->size - 1;
	return data;
}

int front(Queue* q) {
	if (isEmpty(q))
		return INT_MIN;
	return q->arr[q->front];
}

int rear(Queue* q) {
	if (isEmpty(q))
		return INT_MIN;
	return q->arr[q->rear];
}

int main() {
	Queue* q = create_queue(10);
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	enqueue(q, 40);
	cout << "dequeued from queue: " << dequeue(q) << endl;
	cout << "Front of queue" << front(q) << endl;
	cout << "Rear of queue" << rear(q) << endl;
	return 0;
}