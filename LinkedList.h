#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <typename T>
class Node {
public:
	T data; // data
	Node* link; // pointing next Node

	Node(T element) {
		// data initialization
		data = element;
		link = 0;
	}
};

//LinkedList Class
template <typename T>
class LinkedList {
protected:
	Node<T>* first; // address of first Node
	int current_size; // the number of all Nodes in list
public:
	LinkedList() {
		// constructor
		first = 0;
		current_size = 0;
	};

	int GetSize() {
		// return size of list
		return current_size;
	};

	// insert the first Node
	void Insert(T element);

	// delete the last Node  - LinkedList
	virtual bool Delete(T& element);

	// print all list
	void Print();
};


// Node insertion & initialization
template <typename T>
void LinkedList<T>::Insert(T element) {
	// construct new Node
	Node<T>* newnode = new Node<T>(element);

	// newnode becomes the first node
	// newnode is a pointer
	// use operator -> to call functions or variables
	newnode->link = first;
	first = newnode;
	current_size++;
}

// return data of the last Node & delete (free memory)
template <typename T>
bool LinkedList<T>::Delete(T& element) {
	if (first == 0)
		return false;

	Node<T>* current = first;
	Node<T>* previous = 0;

	// go to the last node
	while (1) {
		if (current->link == 0) {  // find the last node
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;

	return true;
}

// print all list
template <typename T>
void LinkedList<T>::Print() {
	Node<T>* i; // searching node pointer
	int index = 1;

	if (current_size != 0) {
		for (i = first; i != NULL; i = i->link) {
			if (index == current_size) {
				// the last node
				cout << "[" << index << "|";
				cout << i->data << "]";
			}
			else {
				cout << "[" << index << "|";
				cout << i->data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}
#endif
