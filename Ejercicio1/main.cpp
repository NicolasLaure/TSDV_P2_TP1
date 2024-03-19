#include <iostream>
//#include "Container.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;


template<typename T>
void Generator(List<T>* list, Queue<T>* queueData, Stack<T>* stackData);

template<typename T>
void Generator(Queue<T>* queue, int quantity);

template<typename T>
void Generator(Stack<T>* stack, int quantity);

template<typename T>
void SortedInsert(List<T>* list, T value);

void main()
{
	srand(time(nullptr));

	Queue<float>* queue = new Queue<float>;
	Stack<float>* stack = new Stack<float>;
	List<float>* list = new List<float>;

	int randomQuantity = rand() % 6 + 5;
	Generator(queue, randomQuantity);
	randomQuantity = rand() % 6 + 5;
	Generator(stack, randomQuantity);
	Generator(list, queue, stack);

	cout << "Quantity of numbers: " << list->GetCount() << endl;
	for (int i = 0; i < list->GetCount(); i++)
	{
		cout << list->GetValueAt(i) << endl;
	}
}

template<typename T>
void Generator(List<T>* list, Queue<T>* queueData, Stack<T>* stackData)
{
	for (int i = 0; i < queueData->GetCount(); i++)
	{
		T value = queueData->Dequeue();
		SortedInsert(list, value);
	}
	for (int i = 0; i < stackData->GetCount(); i++)
	{
		T value = stackData->Pop();
		SortedInsert(list, value);
	}
}

template<typename T>
void Generator(Queue<T>* queue, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		float numberToPush = rand() % 100;
		queue->Enqueue(numberToPush);
	}
}

template<typename T>
void Generator(Stack<T>* stack, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		float numberToPush = rand() % 100;
		stack->Push(numberToPush);
	}
}

template<typename T>
void SortedInsert(List<T>* list, T value)
{
	if (list->GetCount() == 0)
	{
		list->PushFront(value);
		return;
	}

	for (int i = 0; i < list->GetCount(); i++)
	{
		if (value < list->GetValueAt(i))
		{
			list->Insert(value, i);
			break;
		}
	}
	if (value > list->GetValueAt(list->GetCount() - 1))
		list->PushBack(value);
}
//template<typename T, class Type>
//concept Collection = derived_from<Type, Container<T>>;
//
//template<typename T, >
//void Generator(int quantity)
//{
//
//}