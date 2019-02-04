#pragma once
#include "Location.h"
#include "Identifiable.h"
#include "Blackboard.h"
#include <string>
#include <vector>
using namespace std;
class Command : public Identifiable
{
private:
	virtual bool CheckBoard();
public:
	Command(vector<string> _idents);
	~Command();
	virtual string Execute(vector<string> _input, Location* _loc, Entity* _player);
};

