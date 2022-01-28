#include<iostream>
#include"HashTable.h"


int main()
{
	HashTable<string> ht(10);

	ht.Insert(pair<int, string>(25, "A"));

	ht.Insert(pair<int, string>(15, "B"));

	ht.erase(pair<int, string>(5, "B"));

	cout << ht.Find(pair<int, string>(25, "B")) << endl << endl;

	auto container = ht.getlist(105);
	list<string>::iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		cout << *it << endl;
}