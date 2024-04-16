#include <iostream>
#include <iomanip>
#include "Generator.h"

using namespace std;

void main()
{
	srand(time(nullptr));

	Queue<float>* queue = new Queue<float>;
	Stack<float>* stack = new Stack<float>;
	List<float>* list = new List<float>;
	Generator<float> generator;

	int randomQuantity = rand() % 6 + 5;
	cout << randomQuantity << endl;
	generator.QueueGenerator(queue, randomQuantity);
	randomQuantity = rand() % 6 + 5;
	cout << randomQuantity << endl;
	generator.StackGenerator(stack, randomQuantity);

	cout << "Queue: ";
	for (int i = 0; i < queue->GetCount(); i++)
	{
		cout << queue->GetValueAt(i) << ", ";
	}
	cout << "\n------------\n";

	cout << "Stack: ";
	for (int i = 0; i < stack->GetCount(); i++)
	{
		cout << stack->GetValueAt(i) << ", ";
	}
	cout << "\n------------\n";

	generator.QueueAndStackMerger(list, queue, stack);

	cout << "Quantity of numbers: " << list->GetCount() << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < list->GetCount(); i++)
	{
		cout << static_cast<float>(list->GetValueAt(i)) << endl;
	}

	delete queue;
	delete stack;
	delete list;
}

