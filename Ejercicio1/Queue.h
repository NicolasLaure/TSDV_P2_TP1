#pragma once
#include "List.h"

template <typename T>
class Queue
{
private:
	List<T> list;

public:

	Queue();
	~Queue();

	void Enqueue(T data);
	T Dequeue();
	T GetValueAt(int index);
	int GetCount();
};

#include "Queue.tpp"
