#include "Attack.h"

Attack::Attack() : Command(vector<string> {"attack"}) {}
Attack::~Attack(){}

string Attack::Execute(vector<string> _input, Location* _loc, Entity* _player)
{
	if (_input.size() < 2)
		return string();
	
	if (_loc->GetEntity(_input[1]).FindComponent("combat")) 
		return _input[1] + " - HP: " + to_string(static_cast<Combat*>(_player->FindComponent("combat"))->Attack(_loc->GetEntity(_input[1])));

	return string();
}

