#include "Combat.h"

Combat::Combat(int _hp, int _dmg) : Component(vector<string> {"combat"})
{
	health = _hp;
	damage = _dmg;
}

Combat::~Combat()
{
}

int Combat::Attack(Entity _e)
{
	Combat* c = static_cast<Combat*>(_e.FindComponent("combat"));
	return c->Hit(damage);
}

int Combat::Hit(int _dmg)
{
	health -= _dmg;
	return health;
}

void Combat::print()
{
	cout << "HP: " << health << endl;
}
