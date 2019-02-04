#include "Entity.h"
#include <iostream>
Entity::Entity(vector<string> _idents) : Identifiable(_idents){}

Entity::Entity(vector<string> _idents, vector<Component*> _comps) : Identifiable(_idents)
{
	components = _comps;
}

Entity::Entity(vector<string> _idents, vector<Component*> _comps, string _look) : Identifiable(_idents)
{
	components = _comps;
	look = _look;
}

Entity::~Entity(){}

Component* Entity::FindComponent(string _comp)
{
	for (int i = 0; i < components.size(); i++) 
		if (components[i]->AreYou(_comp))
			return components[i];

	return NULL;
}

void Entity::AddComponent(Component * c)
{
	components.push_back(c);
}

bool Entity::Empty()
{
	return Name == ""; //if entity has no identifiers it will be empty
}


