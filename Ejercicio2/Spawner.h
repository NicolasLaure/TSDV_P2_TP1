#pragma once
#include "Entity.h"
#include "Spawnable.h"

template<typename T>
concept SpawnableEntity = std::derived_from<T, Entity> && std::derived_from<T, Spawnable>;

template<SpawnableEntity T, int N>
class Spawner
{
private:
	T spawnableObjects[N];

	bool IsAnyCharacterActive();
public:
	Spawner();
	~Spawner();
	void Spawn(int color);
	void Despawn();
};

#include "Spawner.tpp"