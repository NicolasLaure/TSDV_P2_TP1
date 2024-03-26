#pragma once
#include "Entity.h"
#include "Spawnable.h"

class Character : Entity, Spawnable
{
public:
	Character();
	~Character();
};