#pragma once
#include "Gamestate.h"
#include "Gameplay.h"
#include "HallOfFame.h"
#include <vector>
//using namespace std;

class StateManager
{
public:
	StateManager();
	~StateManager();
	void changeState(string _name);
	Gameplay game;
	HallOfFame hall;
};

