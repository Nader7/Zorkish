#include "Item.h"
#include "Component.h"

Item::Item(vector<string> _idents) : Entity(_idents) {}
Item::~Item() {}

void Item::use()
{
}

Item::Item(vector<string> _idents, vector<Component*> _comps, string _desc, string _locDesc, int _weight) : Entity(_idents, _comps)
{
	weight = _weight;
	desc = _desc;
	look = _locDesc;
}

bool operator==(const Item & item1, const Item & item2)
{
	return (item1.Name == item2.Name);
}


bool operator!=(const Item & item1, const Item & item2)
{
	return !(item1.Name == item2.Name);
}

std::ostream & operator<<(std::ostream & aOStream, const Item & aObject)
{
	aOStream << aObject.Name;
	return aOStream;
}
