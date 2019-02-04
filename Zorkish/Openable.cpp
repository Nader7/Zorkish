#include "Openable.h"



Openable::Openable(bool _open) : Component(vector<string> {"openable"})
{
	open = _open;
}


Openable::~Openable()
{
}
