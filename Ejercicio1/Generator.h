#pragma once
#include "List.h"
#include "Queue.h"
#include "Stack.h"

template<typename T>
class Generator
{
public:
	void QueueAndStackMerger(List<T>* list, Queue<T>* queueData, Stack<T>* stackData);
	void QueueGenerator(Queue<T>* queue, int quantity);
	void StackGenerator(Stack<T>* stack, int quantity);
	void SortedInsert(List<T>* list, T value);
};

#include "Generator.tpp"