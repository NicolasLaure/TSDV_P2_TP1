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
		float numberToPush = rand() % 100 + ((float)rand() / (float)RAND_MAX);
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