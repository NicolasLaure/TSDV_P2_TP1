#ifndef SPAWNER_TPP
#define SPAWNER_TPP

#include <Windows.h>
#include "Spawner.h"

template<SpawnableEntity T, int N>
Spawner<T, N>::Spawner()
{
}

template<SpawnableEntity T, int N>
Spawner<T, N>::~Spawner()
{
}

template<SpawnableEntity T, int N>
void Spawner<T, N>::Spawn(int color)
{
	for (int i = 0; i < N; i++)
	{
		if (!spawnableObjects[i].IsActive())
		{
			spawnableObjects[i].color = color;
			spawnableObjects[i].SetActive(true);
			return;
		}
	}
	spawnableObjects[0].SetActive(false);
	for (int i = 1; i < N; i++)
	{
		spawnableObjects[i - 1] = spawnableObjects[i];
	}
	spawnableObjects[N - 1].color = color;
	spawnableObjects[N - 1].SetActive(true);
}

template<SpawnableEntity T, int N>
void Spawner<T, N>::Despawn()
{
	if (!IsAnyCharacterActive())
		return;

	int randIndex = rand() % N;
	while (!spawnableObjects[randIndex].IsActive())
		randIndex = rand() % N;

	spawnableObjects[randIndex].SetActive(false);
	for (int i = randIndex; i < N; i++)
	{
		if (i + 1 >= N || !spawnableObjects[i + 1].IsActive())
			return;

		spawnableObjects[i] = spawnableObjects[i + 1];
	}
}

template<SpawnableEntity T, int N>
bool Spawner<T, N>::IsAnyCharacterActive()
{
	for (int i = 0; i < N; i++)
	{
		if (spawnableObjects[i].IsActive())
			return true;
	}
	return false;
}
#endif // !SPAWNER_TPP