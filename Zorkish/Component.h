#pragma once
#include <string>
#include "Identifiable.h"
using namespace std;

class Component : public Identifiable
{
public:
	Component(vector<string> _ids);
	~Component();
	friend bool operator== (const Component *comp1, const string &compName);
};

