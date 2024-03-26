#pragma once
#include "Entity.h"
#include "Spawnable.h"

class Character : public Entity, public Spawnable
{
public:
	int color;

	Character();
	~Character();

	void Draw() override;
	void SetPosition(int newX, int newY) override;
	void SetActive(bool state) override;
	virtual bool IsActive() override;
};