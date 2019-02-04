#pragma once
#include "HallOfFame.h"
#include "item.h"
#include "Location.h"
#include "GameState.h"
#include "Entity.h"
#include "Combat.h"
#include "Inventory.h"
#include "Openable.h"
#include "CommandManager.h"
#include "Blackboard.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>


class Gameplay : public GameState
{
private:
	int score;
	Entity player;
	string world, worldDesc;
public:
	Location startLocation;
	Gameplay();
	Gameplay(int _stage);
	virtual ~Gameplay();
	void NewHighScore();
	virtual void start() override;
	void LoadWorld(string _world);
	vector<Component*> CreateComponents(vector<string> _comps, vector<Item> _items);
	vector<std::string> splitR(const std::string &s, char delim);
	void split(const std::string &s, char delim, back_insert_iterator<vector<string>> result);
};

