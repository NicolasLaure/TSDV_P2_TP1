#pragma once

template <typename T>
class Node
{
private:
	T data;
	Node<T>* next;

public:

	Node(T data);
	~Node();

	Node<T>* GetNext();
	void SetNext(Node<T>* next);
	T GetData();
};

#include "Node.tpp"