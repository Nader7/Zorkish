#pragma once
#include "Gameplay.h"
#include "HallOfFame.h"
#include "GameState.h"
#include "StateManager.h"
#include <iostream>
#include <string>

class MainMenu : public GameState
{
private:
	StateManager state;
public:
	MainMenu();
	~MainMenu();
	virtual void start() override;
	void About();
	void Help();
	void SelectAdventure();
};

