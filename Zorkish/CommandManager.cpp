#include "CommandManager.h"

CommandManager::CommandManager(){
	commands = { &attack, &look, &open, &take };
}

CommandManager::~CommandManager(){}

string CommandManager::Execute(vector<string> _input, Location * _loc, Entity * _player)
{
	if (_input.empty())
		return "Command not found";

	for (int i = 0; i < commands.size(); i++) {
		if (commands[i]->AreYou(_input[0]))
			return commands[i]->Execute(_input, _loc, _player);
	}
	
	return "Command not found";
}
