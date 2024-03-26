#include <iostream>
#include <conio.h>
#include "Character.h"

using namespace std;

void main()
{
	bool isRunning = true;
	while (isRunning)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'r':
			case 'R':
				cout << "Rojo";
				break;
			case 'g':
			case 'G':
				cout << "Verde";
				break;
			case 'b':
			case 'B':
				cout << "Azul";
				break;
			case 'd':
			case 'D':
				cout << "Borrar";
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