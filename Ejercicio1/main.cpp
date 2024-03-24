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

	int randomQuantity = rand() % 6 + 5;
	Generator(queue, randomQuantity);
	randomQuantity = rand() % 6 + 5;
	Generator(stack, randomQuantity);
	Generator(list, queue, stack);

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

