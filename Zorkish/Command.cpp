#include "Command.h"

bool Command::CheckBoard()
{
	return false;
}

Command::Command(vector<string> _idents) : Identifiable(_idents){}

Command::~Command(){}

string Command::Execute(vector<string> _input, Location * _loc, Entity* _player)
{
	return string();
}
