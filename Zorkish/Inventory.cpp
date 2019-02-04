#include "Inventory.h"

std::vector<Item>::iterator Inventory::GetIterator(int _pos)
{
	std::vector<Item>::iterator it = inventory.begin();
	for (int i = 0; i < _pos; i++)
		it++;
	return it;
}

Inventory::Inventory() : Component(vector<string> {"inventory"}) {}

Inventory::Inventory(vector<Item> _items) : Component(vector<string> {"inventory"}) {
	inventory = _items;
}

Inventory::~Inventory() {}

bool Inventory::CheckItem(string _id)
{
	for (int i = 0; i < inventory.size(); i++)
		if (inventory[i].Name == _id)
			return true;

	return false;
}

void Inventory::PutItem(Item _item)
{
	inventory.push_back(_item);
}

void Inventory::putAtIndex(int _index, Item _item)
{
	inventory.insert(GetIterator(_index), _item);
}

Item Inventory::GetItem(string _id)
{
	for (int i = 0; i < inventory.size(); i++)
		if (inventory[i].AreYou(_id))
			return inventory[i];
	return Item(vector<string>()); //empty Item
}

Item Inventory::TakeItem(string _id)
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].AreYou(_id)) {
			Item item = inventory[i];
			inventory.erase(GetIterator(i));
			return item;
		}
	}
	return Item(vector<string>()); //empty Item
}

bool Inventory::DropItem(string _id)
{
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].AreYou(_id)){
			inventory.erase(GetIterator(i));
			return true; //item found
		}
	}
	return false; //item not found
}

bool Inventory::HasItem(string _id)
{
	for (int i = 0; i < inventory.size(); i++) 
		if (inventory[i].AreYou(_id))
			return true;
		
		//return inventory[i].AreYou(_id) ? true : false;
	
	return false; //Item not found
}

string Inventory::Open()
{
	if (inventory.empty())
		return string();
	string items;
	//items += "Inventory Contents: ";
	for (int i = 0; i < inventory.size() - 1; i++)
		items += inventory[i].Name + ", ";
	items += inventory.back().Name;
	return items;
}

