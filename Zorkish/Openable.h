#pragma once
#include "Component.h"
class Openable : public Component
{
public:
	Openable(bool _open);
	~Openable();
	bool open;
};

