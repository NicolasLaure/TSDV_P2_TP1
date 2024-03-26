#pragma once

class Spawnable
{
protected:
	int x;
	int y;
	bool isActive;
public:

	virtual void SetPosition(int newX, int newY) = 0;
	virtual void SetActive(bool state) = 0;
	virtual bool IsActive() = 0;

};