#ifndef NODE_TPP
#define NODE_TPP

#include "Node.h"

template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
	next = nullptr;
}
template <typename T>
Node<T>::~Node()
{
	if (next != nullptr)
	{
		delete next;
	}
}
template <typename T>
Node<T>* Node<T>::GetNext()
{
	return next;
}
template <typename T>
void Node<T>::SetNext(Node<T>* next)
{
	this->next = next;
}
template <typename T>
T Node<T>::GetData()
{
	return data;
}

#endif // !NODE_TPP