#pragma once
#include "Component.h"
#include "Item.h"

#include <vector>
#include <iostream>
using namespace std;

class Inventory : public Component
{
private:
	vector<Item> inventory;
	std::vector<Item>::iterator GetIterator(int _pos);
public:
	Inventory();
	Inventory(vector<Item> _items);
	~Inventory();
	bool CheckItem(string _id);
	void PutItem(Item _item);
	void putAtIndex(int _index, Item _item);
	Item GetItem(string _id);
	Item TakeItem(string _id);
	bool DropItem(string _id);
	bool HasItem(string _id);
	string Open();
};

