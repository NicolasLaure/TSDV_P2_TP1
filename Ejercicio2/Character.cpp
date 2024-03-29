#include <iostream>
#include <Windows.h>
#include "Character.h"

Character::Character()
{
	isActive = false;
	color = 0;
}

Character::~Character()
{

}

void Character::Draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)x,(short)y });
	std::cout << "O";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(x - 1),(short)(y + 1) });
	std::cout << "/|\\";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(x - 1),(short)(y + 2) });
	std::cout << "/ \\";
}

void Character::UnDraw()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)x,(short)y });
	std::cout << " ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(x - 1),(short)(y + 1) });
	std::cout << "   ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(x - 1),(short)(y + 2) });
	std::cout << "   ";
}

void Character::SetPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Character::SetActive(bool state)
{
	isActive = state;
	if (!isActive)
	{
		UnDraw();
		return;
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	int randX = rand() % width;
	int randY = rand() % height;
	SetPosition(randX, randY);
	Draw();
}

bool Character::IsActive()
{
	return isActive;
}
