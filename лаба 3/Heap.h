#pragma once

#include "Iterator.h"
#include "LinkedList.h"

class Heap
{

public:
	const int size = 100;
	int* heap;
	int HeapSize;

	Heap();
	~Heap();

	bool contains(int number);
	void insert(int number);
	void remove(int number);
	void heapify(int index);
	void siftDown(int index);
	void siftUp(int index);
	void out();

	Iterator* create_bft_iterator();
	Iterator* create_dft_iterator();

	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int* current, int HeapSize, int index);
		~bft_iterator();
		int next() override;
		bool has_next() override;

	private:
		int* current;
		int HeapSize;
		int index;
	};

	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* current, int HeapSize, int index);
		~dft_iterator();
		int next() override;
		bool has_next() override;

	private:
		int* current;
		int HeapSize;
		int index;
		LinkedList stack;
	};
};