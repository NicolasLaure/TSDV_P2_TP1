#pragma once
#include "Entity.h"
#include "Spawnable.h"

class Character : Entity, Spawnable
{
public:
	Character();
	~Character();

	void Draw() override;
	void SetPosition(int newX, int newY) override;
	void SetActive(bool state) override;
};