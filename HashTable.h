#pragma once
#include<list>
//Fahad Waheed

using namespace std;

template <typename V>
class HashTable
{
	int X;
	list<V>* L;

public:
	HashTable() : X(int()), L(NULL) {};

	HashTable(int x)
	{
		if (x > 0)
			X = x, L = new list<V>[X];
		else
			X = int(), L = NULL;
	}

	bool validHashTable()
	{
		return X != 0 && L != NULL;
	}

	//hash by division
	int hashfunction(int key)
	{
		return key % X;
	}

	//hash by multiplication
	int hashfunction(int key, double A)
	{
		return X * ((key * A) - int(key * A));
		//e.g; 10 * (9.5 - 9) = 10 * 0.5 = 5
		//0 < A < 1
		//A must not be close to zero or close to 1 for better result
	}

	void Insert(pair<int, V> P)
	{
		int key = hashfunction(P.first);
		if (validHashTable())
		{
			typename list<V>::iterator it;
			auto& container = L[key];

			for (it = container.begin(); it != container.end(); ++it)
				if ((*it) == P.second)
					return;

			container.push_back(P.second);
		}
	}

	bool Find(pair<int, V> P)
	{
		int key = hashfunction(P.first);
		if (validHashTable())
		{
			auto& container = L[key];

			typename list<V>::iterator it;
			for (it = container.begin(); it != container.end(); ++it)
				if ((*it) == P.second)
					return true;
		}
		return false;
	}

	void erase(pair<int, V> P)
	{
		int key = hashfunction(P.first);
		if (validHashTable())
		{
			auto& container = L[key];

			typename list<V>::iterator it;
			for (it = container.begin(); it != container.end(); ++it)
				if ((*it) == P.second)
				{
					container.erase(it);
					return;
				}
		}
	}

	auto getlist(int key)
	{
		int Key = hashfunction(key);
		if (validHashTable())
			return L[Key];
	}

	~HashTable()
	{
		if (L)
			delete[] L;
		L = NULL;
		X = 0;
	}
};