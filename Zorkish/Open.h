#pragma once
#include "Location.h"
#include "Openable.h"
#include "Command.h"
#include <string>
#include <vector>

using namespace std;

class Open : public Command
{
public:
	Open();
	~Open();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player) override;
};

