#pragma once
#include "Component.h"
#include "Identifiable.h"
#include <vector>
#include <string>

using namespace std;

class Entity : public Identifiable
{
private:
	vector<Component*> components;
public:
	Entity(vector<string> _idents);
	Entity(vector<string> _idents, vector<Component*> _comps);
	Entity(vector<string> _idents, vector<Component*> _comps, string _look);
	~Entity();
	string look;
	Component* FindComponent(string _comp);
	void AddComponent(Component* c);
	bool Empty();
};

