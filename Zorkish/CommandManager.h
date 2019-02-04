#pragma once
#include "Attack.h"
#include "Go.h"
#include "Look.h"
#include "Open.h"
#include "Take.h"
#include "Location.h"
#include "Entity.h"
#include "Command.h"
#include <string>
#include <vector>

using namespace std;
class CommandManager
{
private:
	Attack attack;
	//Go go; //needs to access start location within gameplay to work
	Look look;
	Open open;
	Take take;
	vector<Command*> commands; 

public:
	CommandManager();
	~CommandManager();
	string Execute(vector<string> _input, Location* _loc, Entity* _player);
};

