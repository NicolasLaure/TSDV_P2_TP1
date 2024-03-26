#include <iostream>
#include <conio.h>
#include "Spawner.h"
#include "Character.h"

using namespace std;

void main()
{
	Spawner<Character, 5> spawner;

	bool isRunning = true;
	while (isRunning)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'r':
			case 'R':
				spawner.Spawn(4);
				cout << "Rojo";
				break;
			case 'g':
			case 'G':
				spawner.Spawn(10);
				cout << "Verde";
				break;
			case 'b':
			case 'B':
				spawner.Spawn(9);
				cout << "Azul";
				break;
			case 'd':
			case 'D':
				cout << "Borrar";
				break;
			case 'q':
			case 'Q':
				isRunning = false;
				break;
			default:
				break;
			}
		}
	}
}