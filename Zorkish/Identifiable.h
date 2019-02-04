#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
class Identifiable
{
private:
	vector<string> idents;
public:
	Identifiable(vector<string> _idents);
	~Identifiable();

	bool AreYou(string _id);
	void AddIdentifier(string _id);
	string Name;
};

