#include <stdexcept>
#include "iostream"
#include "LinkedList.h"

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::add_first(int newElem)
{
	head = new Node(newElem);
	tail = head;
}

void LinkedList::push_back(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Node(newElem, nullptr, tail);
		tail = tail->next;
	}
	size++;
}

void LinkedList::push_front(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head = new Node(newElem, head);
		head->next->prev = head;
	}
	size++;
}

void LinkedList::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

void LinkedList::pop_front()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head->next;
		current->prev = nullptr;
		delete head;
		head = current;
	}
	size--;
}

void LinkedList::insert(int newElem, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else if (index == 0) {
		push_front(newElem);
	}
	else {
		Node* current = head;
		size_t counter = 0;
		while (counter != index - 1) {
			current = current->next;
			counter++;
		}
		current->next = new Node(newElem, current->next, current);
		current = current->next;
		current->next->prev = current;
		current->prev->next = current;
		size++;
	}
}

int LinkedList::at(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		Node* current = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

void LinkedList::remove(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node* current = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		size--;
	}
}

size_t LinkedList::get_size()
{
	return size;
}

void LinkedList::print_to_console()
{
	Node* current = head;
	while (current->next != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << current->data << " ";
}

void LinkedList::clear()
{
	Node* current = head->next;
	while (current->next != nullptr) {
		delete head;
		head = current;
		current = head->next;
	}
	delete head;
	delete tail;
	size = 0;
}

void LinkedList::set(size_t index, int newElem)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	Node* current = head;
	size_t counter = 0;
	while (counter != index) {
		current = current->next;
		counter++;
	}
	current->data = newElem;
}

bool LinkedList::isEmpty() // if empty - true, else false
{
	return !size;
}

