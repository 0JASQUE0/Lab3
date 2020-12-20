#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap()
{
	heap = new int[size];
	HeapSize = 0;
}

Heap::~Heap()
{
	delete heap;
	HeapSize = 0;
}

void Heap::siftDown(int index) {
	int left, right;
	int j, temp;
	while (2 * index + 1 < HeapSize) {
		left = 2 * index + 1;
		right = 2 * index + 2;
		j = left;
		if (right < HeapSize && heap[right] < heap[left])
			j = right;
		if (heap[index] <= heap[j])
			break;
		temp = heap[index];
		heap[index] = heap[j];
		heap[j] = temp;
		index = j;
	}
}

void Heap::siftUp(int index) {
	int temp;
	while (heap[index] < heap[(index - 1) / 2]) {
		temp = heap[index];
		heap[index] = heap[(index - 1) / 2];
		heap[(index - 1) / 2] = temp;
		index = (index - 1) / 2;
	}
}

void Heap::heapify(int index)
{
	if (heap[index] > heap[2 * index + 1] || heap[index] > heap[2 * index + 2]) siftDown(index);
	if (heap[index] < heap[(index - 1) / 2]) siftUp(index);
}



void Heap::insert(int number)
{
	int index;
	index = HeapSize;
	heap[index] = number;
	HeapSize++;
	heapify(index);
}

bool Heap::contains(int number)
{
	for (int i = 0; i < HeapSize; i++) {
		if (heap[i] == number) return true;
	}
	return false;
}

void Heap::remove(int number)
{
	int temp, index;
	bool flag = false;
	for (int i = 0; i < HeapSize; i++) {
		if (heap[i] == number) {
			flag = true;
			index = i;
			break;
		}
	}

	if (flag == true) {
		temp = heap[index];
		heap[index] = heap[HeapSize - 1];
		heap[HeapSize - 1] = temp;
		HeapSize--;
		heapify(index);
	}
	else throw("There is no such element");
}

void Heap::out()
{
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			cout << heap[i] << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}

Iterator* Heap::create_bft_iterator()
{
	return new bft_iterator(heap, size, 0);
}

Heap::bft_iterator::bft_iterator(int* current, int HeapSize, int index = 0)
{
	this->current = current;
	this->HeapSize = HeapSize;
	this->index = index;
}

Heap::bft_iterator::~bft_iterator()
{
	delete current;
}

int Heap::bft_iterator::next()
{
	if (!has_next())
		throw ("No more elements");
	index++;
	return current[index - 1];
}

bool Heap::bft_iterator::has_next()
{
	return index != this->HeapSize;
}

Iterator* Heap::create_dft_iterator()
{
	return new dft_iterator(heap, HeapSize, 0);
}

Heap::dft_iterator::dft_iterator(int* current, int HeapSize, int index = 0)
{
	this->current = current;
	this->HeapSize = HeapSize;
	this->index = index;
}

Heap::dft_iterator::~dft_iterator()
{
	delete current;
}

int Heap::dft_iterator::next()
{
	if (!has_next())
		throw ("No more elements");
	int temp = current[index];
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (index == 0) stack.push_back(0);
	if (right < this->HeapSize) {
		stack.push_back(right);
		index = left;
	}
	else if (left < this->HeapSize) index = left;
	else {
		if (stack.at(stack.get_size() - 1) == 0)
			stack.pop_back();
		else {
			index = stack.at(stack.get_size() - 1);
			stack.pop_back();
		}
		if (this->HeapSize == 1) index = -1;
	}
	return temp;
}

bool Heap::dft_iterator::has_next()
{
	if (HeapSize == 0) return false;
	if (index == 0) return true;
	if (stack.isEmpty() && index != 0) return false;
	else return true;
}