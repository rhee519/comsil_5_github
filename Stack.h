#include "LinkedList.h"

//1. expand to template class
//2. override delete function with the structure of stack
// remark: use keyword this
// to call first, current_size (member function)

// derive from class LinkedList
template <typename T>
class Stack : public LinkedList<T> {
public:
	bool Delete(T& element) {
		// return false if first is NULL
		if (this->first == NULL) {
			// nothing in stack
			return false;
		}

		Node<T>* current = this->first;
		this->first = this->first->link;
		element = current->data;
		delete current;
		this->current_size--;

		// unlike in LinkedList,
		// delete where current is pointing in Stack
		return true;
	}
};