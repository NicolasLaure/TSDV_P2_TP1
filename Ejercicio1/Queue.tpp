#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
	list = List<T>();
}

template <typename T>
Queue<T>::~Queue()
{
	list.Clear();
}

template <typename T>
void Queue<T>::Enqueue(T data)
{
	list.PushBack(data);
}

template <typename T>
T Queue<T>::Dequeue()
{
	return list.PopFront();
}

template <typename T>
T Queue<T>::GetValueAt(int index)
{
	return list.GetValueAt(index);
}

template <typename T>
int Queue<T>::GetCount()
{
	return list.GetCount();
}
#endif // !QUEUE_TPP
