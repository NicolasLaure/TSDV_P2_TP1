#pragma once
#include "List.h"
#include "Queue.h"
#include "Stack.h"

template<typename T>
void Generator(List<T>* list, Queue<T>* queueData, Stack<T>* stackData);

template<typename T>
void Generator(Queue<T>* queue, int quantity);

template<typename T>
void Generator(Stack<T>* stack, int quantity);

template<typename T>
void SortedInsert(List<T>* list, T value);

#include "Generator.tpp"