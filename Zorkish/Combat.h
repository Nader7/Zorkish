#pragma once
#include "Component.h"
#include "Entity.h"
#include <iostream>
using namespace std;

class Combat : public Component
{
private:
	int health, damage;
public:
	Combat(int _hp, int _dmg);
	~Combat();

	int Attack(Entity _e);
	int Hit(int _dmg);
	void print();
};

