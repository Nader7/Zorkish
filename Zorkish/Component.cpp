#include "Component.h"



Component::Component(vector<string> _ids) : Identifiable(_ids)	{}

Component::~Component(){}

bool operator==(const Component * comp1, const string & compName)
{
	return comp1->Name == compName;
}