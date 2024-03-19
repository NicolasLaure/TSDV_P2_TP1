#pragma once
#include "List.h"

template <typename T>
class Stack
{
private:
	List<T> list;

public:
	Stack();
	~Stack();

	void Push(T data);
	T Pop();
	T GetValueAt(int index);
	int GetCount();
};

#include "Stack.tpp"