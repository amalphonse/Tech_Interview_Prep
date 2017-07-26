#include<iostream>

using namespace std;

void swap(int* x, int*y);

class MinHeap {
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity);

	//to heapify the heap
	void min_heapify(int i);

	int extract_min();

	int parent(int i) {
		return ((i - 1) / 2);
	}

	int left(int i) {
		return ((2 * i) + 1);
	}

	int right(int i) {
		return ((2 * i) + 2);
	}

	int getMin() {
		return harr[0];
	}

	void insert_key(int new_val);

	void decrease_key(int i, int new_val);

	void delete_key(int i);
};

MinHeap::MinHeap(int cap) {
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insert_key(int new_val) {
	if (heap_size > capacity)
		cout << "The heap is overflowing." << endl;
	heap_size++;
	int i = heap_size - 1;
	harr[i] = new_val;

	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decrease_key(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::extract_min() {
	if (heap_size <= 0) {
		return INT_MAX;
	}
	if (heap_size == 1) {
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	min_heapify(0);

	return root;
}

void MinHeap::delete_key(int i) {
	decrease_key(i, INT_MIN);
	extract_min();
}

void MinHeap::min_heapify(int i) {
	int smallest = i;
	int l = left(i);
	int r = right(i);
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		min_heapify(smallest);
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	MinHeap h(11);
	h.insert_key(3);
	h.insert_key(2);
	h.delete_key(1);
	h.insert_key(15);
	h.insert_key(5);
	h.insert_key(4);
	h.insert_key(45);
	cout << h.extract_min() << " ";
	cout << h.getMin() << " ";
	h.decrease_key(2, 1);
	cout << h.getMin();
	return 0;
}

