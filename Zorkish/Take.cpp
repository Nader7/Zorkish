#include "Take.h"

Take::Take() : Command(vector<string> {"take", "get"}){}

Take::~Take(){}

string Take::Execute(vector<string> _input, Location* _loc, Entity* _player)
{
	if (_input.size() < 2)
		return string();

	if (_input.size() < 3 && !_loc->GetItem(_input[1]).Empty()) {
		static_cast<Inventory *>(_player->FindComponent("inventory"))->PutItem(_loc->TakeItem(_input[1]));
		return "You have taken " + _input[1];
	}
	
	if (_input.size() < 5) {
		if (!_loc->GetEntity(_input[3]).Empty() && static_cast<Inventory*>(_loc->GetEntity(_input[3]).FindComponent("inventory"))->HasItem(_input[1])) {
			static_cast<Inventory*>(_player->FindComponent("inventory"))->PutItem(static_cast<Inventory*>(_loc->GetEntity(_input[3]).FindComponent("inventory"))->TakeItem(_input[1]));
			return "You have taken " + _input[1] + " from " + _input[3];
		}
		if (!_loc->GetItem(_input[3]).Empty() && static_cast<Inventory*>(_loc->GetItem(_input[3]).FindComponent("inventory"))->HasItem(_input[1])) {
			static_cast<Inventory*>(_player->FindComponent("inventory"))->PutItem(static_cast<Inventory*>(_loc->GetItem(_input[3]).FindComponent("inventory"))->TakeItem(_input[1]));
			return "You have taken " + _input[1] + " from " + _input[3];
		}
	}

	return string();
}
