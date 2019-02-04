#pragma once
#include <string>
#include <iostream>

using namespace std;

class GameState
{
public:
	GameState();
	~GameState();
	virtual void start(); 
};

