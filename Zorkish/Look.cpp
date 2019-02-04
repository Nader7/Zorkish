#include "Look.h"

Look::Look() : Command(vector<string> {"look", "examine"}){}

Look::~Look(){}

string Look::Execute(vector<string> _input, Location* _loc, Entity* _player)
{
	if (_input.empty()) 
		return string();

	if (_input.size() < 2 || _input[1] == "around") 
		return "You see " + _loc->look;

	if (_input[1] == "at") {
		if (!_loc->GetEntity(_input[2]).Empty())
			return _loc->GetEntity(_input[2]).look;
		
		if (!_loc->GetItem(_input[2]).Empty())
			return _loc->GetItem(_input[2]).look;
		
		if (static_cast<Inventory*>(_player->FindComponent("inventory"))->HasItem(_input[2]))
			return static_cast<Inventory*>(_player->FindComponent("inventory"))->GetItem(_input[2]).look;
	}

	if (_input[1] == "in") {
		if(_loc->GetItem(_input[2]).FindComponent("inventory"))
			return _input[2] + " contents: " + static_cast<Inventory*>(_loc->GetItem(_input[2]).FindComponent("inventory"))->Open();
		
		if (_loc->GetEntity(_input[2]).FindComponent("inventory"))
			return _input[2] + " contents: " + static_cast<Inventory*>(_loc->GetEntity(_input[2]).FindComponent("inventory"))->Open();
		
		if (static_cast<Inventory*>(static_cast<Inventory*>(_player->FindComponent("inventory"))->GetItem(_input[2]).FindComponent("inventory")))
			return _input[2] + " contents: " + static_cast<Inventory*>(static_cast<Inventory*>(_player->FindComponent("inventory"))->GetItem(_input[2]).FindComponent("inventory"))->Open(); //gets inventory from an item in playeers inventory

	}
	return string();
}