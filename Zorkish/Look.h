#pragma once
#include "Identifiable.h"
#include "Location.h"
#include "Command.h"
#include <vector>
#include <string>
using namespace std;

class Look : public Command
{
public:
	Look();
	~Look();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player) override;
};