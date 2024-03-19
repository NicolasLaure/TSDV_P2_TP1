#ifndef LIST_TPP
#define LIST_TPP

#include "List.h"


template <typename T>
List<T>::List()
{
	first = nullptr;
	this->count = 0;
}

template <typename T>
List<T>::~List()
{
	Clear();
}

template <typename T>
int List<T>::GetCount()
{
	return count;
}

template <typename T>
void List<T>::PushFront(T data)
{
	Node<T>* nodeToPush = new Node<T>(data);
	nodeToPush->SetNext(first);
	first = nodeToPush;
	count++;
}

template <typename T>
void List<T>::PushBack(T data)
{
	Node<T>* nodeToPush = new Node<T>(data);
	Node<T>* lastNode = GetLastNode();
	if (lastNode != nullptr)
		lastNode->SetNext(nodeToPush);
	else
		first = nodeToPush;
	count++;
}

template <typename T>
void List<T>::Insert(T data, int index)
{
	if (index == 0)
	{
		PushFront(data);
	}
	else if (index < count && index > 0)
	{
		if (GetNodeAt(index - 1)->GetNext() != nullptr)
		{
			Node<T>* next = GetNodeAt(index - 1)->GetNext();
			Node<T>* insertedNode = new Node<T>(data);
			GetNodeAt(index - 1)->SetNext(insertedNode);
			insertedNode->SetNext(next);
			count++;
		}
		else
		{
			Node<T>* insertedNode = new Node<T>(data);
			GetPenultimateNode()->SetNext(insertedNode);
			count++;
		}
	}
}

template <typename T>
T List<T>::PopFront()
{
	T poppedData;
	if (first != nullptr)
	{
		Node<T>* next = first->GetNext();
		poppedData = first->GetData();
		first->SetNext(nullptr);
		delete first;
		first = next;
		count--;
	}
	return poppedData;
}

template <typename T>
T List<T>::PopBack()
{
	T lastNodeData;
	if (first != nullptr)
	{
		Node<T>* lastNode = GetLastNode();
		lastNodeData = lastNode->GetData();
		Node<T>* penultimateNode = GetPenultimateNode();
		if (penultimateNode != nullptr)
			penultimateNode->SetNext(nullptr);
		else
			first = nullptr;

		delete lastNode;
		count--;
	}
	return lastNodeData;
}

template <typename T>
T List<T>::PopAt(int index)
{
	T nodeToPopData;
	if (index == 0)
	{
		if (first->GetNext() != nullptr)
		{
			Node<T>* newFirst = first->GetNext();
			nodeToPopData = first->GetData();
			first->SetNext(nullptr);
			delete first;
			first = newFirst;
			count--;
		}
		else
		{
			delete first;
			first = nullptr;
			count = 0;
		}
		return nodeToPopData;
	}
	if (index < count && index != 0)
	{
		Node<T>* nodeToPop = GetNodeAt(index);
		nodeToPopData = nodeToPop->GetData();
		if (nodeToPop->GetNext() != nullptr)
		{
			GetNodeAt(index - 1)->SetNext(nodeToPop->GetNext());
			nodeToPop->SetNext(nullptr);
			delete nodeToPop;
			nodeToPop = nullptr;
		}
		else
		{
			GetPenultimateNode()->SetNext(nullptr);
			delete nodeToPop;
		}
		count--;
		return nodeToPopData;
	}
}

template <typename T>
void List<T>::Clear()
{
	if (first != nullptr)
	{
		delete first;
		first = nullptr;
		count = 0;
	}
}

template <typename T>
Node<T>* List<T>::GetLastNode()
{
	Node<T>* lastNode = first;

	if (first != nullptr)
	{
		while (lastNode->GetNext() != nullptr)
		{
			lastNode = lastNode->GetNext();
		}
	}

	return lastNode;
}

template <typename T>
Node<T>* List<T>::GetPenultimateNode()
{
	Node<T>* lastNode = first;
	Node<T>* penultimateNode = nullptr;
	if (first)
	{
		while (lastNode->GetNext() != nullptr)
		{
			penultimateNode = lastNode;
			lastNode = lastNode->GetNext();
		}
	}
	return penultimateNode;
}

template <typename T>
T List<T>::GetValueAt(int index)
{
	Node<T>* node = nullptr;
	if (index < count)
		for (int i = 0; i <= index; i++)
		{
			if (i == 0)
				node = first;
			else
				node = node->GetNext();
		}
	return node->GetData();
}

template <typename T>
Node<T>* List<T>::GetNodeAt(int index)
{
	Node<T>* node = nullptr;
	if (index < count)
		for (int i = 0; i <= index; i++)
		{
			if (i == 0)
				node = first;
			else
				node = node->GetNext();
		}
	return node;
}

#endif // !LIST_TPP
