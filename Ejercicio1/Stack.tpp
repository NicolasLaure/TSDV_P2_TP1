#ifndef STACK_TPP
#define STACK_TPP

#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
	list = List<T>();
}
template <typename T>
Stack<T>::~Stack()
{
	list.Clear();
}
template <typename T>
void Stack<T>::Push(T data)
{
	list.PushFront(data);
}
template <typename T>
T Stack<T>::Pop()
{
	return list.PopFront();
}
template <typename T>
T Stack<T>::GetValueAt(int index)
{
	return list.GetValueAt(index);
}
template <typename T>
int Stack<T>::GetCount()
{
	return list.GetCount();
}
#endif // !STACK_TPP