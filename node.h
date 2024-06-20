#include "Book.h"

template <class T>
class Node{
	T data;
	Node* Next;
	
	public:
		Node(T&);
		void setData(T&);
		void setNext(Node*);
		T& getData();
		Node* getNext();	
};