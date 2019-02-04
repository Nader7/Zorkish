#pragma once
#include "Location.h"
#include "Combat.h"
#include "Command.h"
#include <vector>
#include <string>

using namespace std;

class Attack : public Command
{
public:
	Attack();
	~Attack();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player) override;
};

