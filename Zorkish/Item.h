#pragma once
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;
class Item : public Entity
{
private:
	int weight;
public:
	Item(vector<string> _idents);
	Item(vector<string> _idents, vector<Component*> _comps, string _desc, string _locDesc, int _weight);
	~Item();
	string desc;
	void use();
	friend bool operator== (const Item &item1, const Item &item2);
	friend bool operator!= (const Item &item1, const Item &item2);
	friend std::ostream& operator<<(std::ostream& aOStream, const Item& aObject);
};

