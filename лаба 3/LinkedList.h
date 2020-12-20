#pragma once

class LinkedList
{
private:

	void add_first(int newElem); //
	void reset_list(); //

	class Node
	{
	public:
		Node(int data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~Node() {}

		int data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	LinkedList();
	~LinkedList();

	void push_back(int newElem); //
	void push_front(int newElem); //
	void pop_back(); //
	void pop_front(); //
	void insert(int newElem, size_t index); //
	int at(size_t index); //
	void remove(size_t index); //
	size_t get_size(); //
	void print_to_console(); //
	void clear(); //
	void set(size_t, int); //	
	bool isEmpty(); //
};

