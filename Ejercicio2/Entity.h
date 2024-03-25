#pragma once

class Entity
{
public:
	virtual ~Entity() = 0;
	virtual void Draw() = 0;
};