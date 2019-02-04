#include "Location.h"

Location::Location() : Identifiable(vector<string>()){}
Location::Location(vector<string> _idents, string _title, string _desc, string _look, vector<Item> _items, vector<string> _dir, int _id, vector<Entity> _entities) : Identifiable(_idents)
{
	title = _title;
	desc = _desc;
	look = _look;
	items = _items;
	directions = _dir;
	id = _id;
	entities = _entities;
}

Location::~Location(){}

void Location::addConnections(vector<Location> _con)
{
	connections = _con;
}

void Location::printContent()
{
	cout << "Current Location: " << title << endl << "Connections: ";
	for (int i = 0; i < connections.size(); i++) {
		cout << connections[i].Name;
	}
	cout << endl << "ITEMS: ";
	for (int i = 0; i < items.size(); i++) {
		cout << items[i] << " ";
	}
	cout << endl;
}

void Location::printText()
{
	cout << title << ": " << desc << endl;
	
	cout << endl << "ITEMS: ";
	for (int i = 0; i < items.size(); i++) {
		cout << items[i] << " ";
	}
	cout << endl << "Entities: ";
	for (int i = 0; i < entities.size(); i++) {
		cout << entities[i].Name << " ";
		if (entities[i].FindComponent("combat")) {
			cout << " - ";
			static_cast<Combat*>(entities[i].FindComponent("combat"))->print();
		}
	}
	cout << endl;
}

Location Location::goTo(string _direction)
{
	for (int i = 0; i < connections.size(); i++) 
		if (connections[i].AreYou(_direction))
			return connections[i];
	
	return *this;
}

Entity Location::GetEntity(string _id)
{
	for (int i = 0; i < entities.size(); i++)
		if (entities[i].AreYou(_id)) {
			return entities[i];
		}
	return Entity(vector<string>());
}

Item Location::GetItem(string _id)
{
	for (int i = 0; i < items.size(); i++)
		if (items[i].AreYou(_id)) 
			return items[i];

	return Item(vector<string>());
}

Item Location::TakeItem(string _id)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i].AreYou(_id)) {
			Item res = items[i];
			items.erase(GetItemIterator(i));
			return res;
		}
	}
	return Item(vector<string>());
}

Entity Location::TakeEntity(string _id)
{
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i].AreYou(_id)) {
			Entity res = entities[i];
			entities.erase(GetEntityIterator(i));
			return res;
		}
	}
	return Entity(vector<string>());
}

vector<Item>::iterator Location::GetItemIterator(int _pos)
{
	vector<Item>::iterator it = items.begin();
	for (int i = 0; i < _pos; i++)
		it++;
	return it;
}

vector<Entity>::iterator Location::GetEntityIterator(int _pos)
{
	vector<Entity>::iterator it = entities.begin();
	for (int i = 0; i < _pos; i++)
		it++;
	return it;
}

bool operator<(const Location & loc1, const Location & loc2)
{
	return (loc1.id < loc2.id);
}
