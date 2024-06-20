#include "node.h"

template <class T>
Node<T> :: Node(T& data)
{
	this->data = data;
	this->Next = NULL;
}

template <class T>
void Node<T> :: setData(T& data)
{
	this->data = data;
}

template <class T>
void Node<T> :: setNext(Node* next)
{
	this->Next = next;
}

template <class T>
T& Node<T> :: getData()
{
	return this->data;
}

template <class T>
Node<T>* Node<T> :: getNext()
{
	return this->Next;
}