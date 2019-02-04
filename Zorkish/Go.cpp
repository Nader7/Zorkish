#include "Go.h"



bool Go::CheckBoard()
{
	for (int i = 0; i < Blackboard().messages.size(); i++) 
		if (Blackboard().messages[i] == "BLOCK")
			return true;

	return false;
}

Go::Go() : Command(vector<string> {"go", "move"}) {}

Go::~Go(){}

string Go::Execute(vector<string> _input, Location* _loc, Entity* _player) //determines which word is the location
{
	if (CheckBoard()) {
		cout << "The enemy is in your way" << endl;
		return string();
	}

	if (_input.size() < 2 || _input.size() > 3)
		return string();

	if (!_loc->GetEntity("door").Empty() && !static_cast<Openable*>(_loc->GetEntity("door").FindComponent("openable"))->open) { //checking if its empty avoids crash when accessing components
		cout << "A door blocks your way" << endl;
		return string();
	}

	if (_input.size() > 2) {
		if (_input[1] == "to") {
			return _input[2];
		}
		return string();
	}
	
	return _input[1];
}
