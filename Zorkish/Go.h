#pragma once
#include <iostream>
#include <vector>
#include "Command.h"
#include "Location.h"
#include "Openable.h"
#include "Blackboard.h"

using namespace std;

class Go : public Command
{
private:
	virtual bool CheckBoard() override;
public:
	Go();
	~Go();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player) override;
};

