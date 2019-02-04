#pragma once
#include "Entity.h"
#include "Location.h"
#include "Command.h"
#include "Identifiable.h"
#include <vector>
#include <string>

using namespace std;

class Take : public Command
{
public:
	Take();
	~Take();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player) override;
};

