#pragma once
#include "HighScore.h"
#include "GameState.h"

#include <iostream>
using namespace std;
class HallOfFame : public GameState
{
public:
	HallOfFame();
	virtual ~HallOfFame();
	virtual void start() override;
	void AddHighScore(int score, string name, string world);
};

