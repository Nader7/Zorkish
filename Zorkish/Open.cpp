#include "Open.h"

Open::Open() : Command(vector<string> {"open"}){}

Open::~Open(){}

string Open::Execute(vector<string> _input, Location* _loc, Entity* _player)
{
	if (_input.size() < 2)
		return string();
	
	if (!_loc->GetEntity("door").Empty()) {
		static_cast<Openable*>(_loc->GetEntity("door").FindComponent("openable"))->open = true;
		return "You have opened the door";
	}

	return string();
}
