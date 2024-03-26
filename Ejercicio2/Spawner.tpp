#ifndef SPAWNER_TPP
#define SPAWNER_TPP

#include <Windows.h>
template<CharacterClass T, int N>
Spawner<T, N>::Spawner()
{
	spawnableObjects = new T[N];
}

template<CharacterClass T, int N>
Spawner<T, N>::~Spawner()
{
}

template<CharacterClass T, int N>
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
}

template<CharacterClass T, int N>
void Spawner<T, N>::Despawn()
{
}
#endif // !SPAWNER_TPP