#pragma once
#include "Node.h"

// Definitions in .h explanation
//https://stackoverflow.com/questions/1639797/template-issue-causes-linker-error-c

template <typename T>
class List
{
private:
	Node<T>* first;
	int count;

public:

	List();
	~List();

	int GetCount();
	void PushFront(T data);
	void PushBack(T data);
	void Insert(T data, int index);
	T PopFront();
	T PopBack();
	T PopAt(int index);
	void Clear();
	Node<T>* GetLastNode();
	Node<T>* GetPenultimateNode();
	T GetValueAt(int index);
	Node<T>* GetNodeAt(int index);
	
};

#include "List.tpp"