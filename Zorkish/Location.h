#pragma once
#include "Item.h"
#include "Entity.h"
#include "Identifiable.h"
#include "Combat.h"
#include "Inventory.h"

#include <string>
#include <map>
#include <vector>
using namespace std;
class Location : public Identifiable
{
private:
	vector<Location> connections;
	vector<Item> items;
	vector<Entity> entities;
	char direction; //from last location
	int id;
public:
	Location();
	Location(vector<string> _idents, string _title, string _desc, string _look, vector<Item> _items, vector<string> _dir, int _id, vector<Entity> _entities);
	~Location();
	void addConnections(vector<Location> _con);
	vector<string> directions;
	void printContent(); //testing
	void printText();
	Location goTo(string _direction);
	
	Entity GetEntity(string _id);
	Item GetItem(string _id);

	Item TakeItem(string _id);
	Entity TakeEntity(string _id);
	
	string title, desc, look;
	
	friend bool operator< (const Location &loc1, const Location &loc2);

	vector<Item>::iterator Location::GetItemIterator(int _pos);
	vector<Entity>::iterator Location::GetEntityIterator(int _pos);

};

