#include "Identifiable.h"

Identifiable::Identifiable(vector<string> _idents)
{
	idents = _idents;
	if (!idents.empty())
		Name = idents[0];
}

Identifiable::~Identifiable(){}

bool Identifiable::AreYou(string _id)
{
	transform(_id.begin(), _id.end(), _id.begin(), tolower);

	for (int i = 0; i < idents.size(); i++)
		if (_id == idents[i])
			return true;

	return false;
}

void Identifiable::AddIdentifier(string _id)
{
	idents.push_back(_id);
}
