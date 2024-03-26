#pragma once
#include "Entity.h"
#include "Spawnable.h"

template<typename T>
concept CharacterClass = std::derived_from<T, Entity> && std::derived_from<T, Spawnable>;

template<CharacterClass T, int N>
class Spawner
{
private:
	T* spawnableObjects;
public:
	Spawner();
	~Spawner();
	void Spawn(int color);
	void Despawn();
};

#include "Spawner.tpp"