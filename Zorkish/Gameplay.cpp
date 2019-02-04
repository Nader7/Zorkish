#include "Gameplay.h"

using namespace std;
Gameplay::Gameplay() : player(vector<string>()) {}

Gameplay::Gameplay(int _stage) : player(vector<string>())
{
	if (_stage > 0 && _stage < 4) //3 worlds
		LoadWorld(to_string(_stage));
}

void Gameplay::LoadWorld(string _world) { 
	
	ifstream file(_world + ".txt");

	if (!file.is_open()) {
		cout << "Cannot find File" << endl;
		return;
	}
	
	vector<Item> items;
	vector<Location> locations;
	vector<Entity> entities;

	while (file.good()) { //LOAD Game FILE
		string input;
		getline(file,input);

		if (input[0] == '#' || input.empty()) 
			continue;

		vector<string> line = splitR(input, '|');
		
		switch (line[0][0]) {
		case 'W': //Load world details
			world = line[1];
			worldDesc = line[2];
			break;
		case 'I': //Load items
		{ //braces allow the intialisation of variables
			vector<string> idents = splitR(line[2], ',');
			vector<Component *> components;
			if (line[6] != "") 
				components = CreateComponents(splitR(line[6], ','), items);

			items.push_back(Item(idents, components, line[3], line[4], atoi(line[5].c_str())));
			break;
		}
		case 'P': //Load players
		{
			vector<string> idents = splitR(line[1], ',');
			vector<Component *> components = CreateComponents(splitR(line[2], ','), items);
			player = Entity(idents,components);
			break;
		}
		case 'E': //Load entities
		{
			vector<string> idents = splitR(line[2], ',');
			vector<Component *> components = CreateComponents(splitR(line[4], ','), items);
			entities.push_back(Entity(idents,components, line[3]));
			break;
		}
		case 'L': //Load locations
			vector<Item> locItems;											//stores items within location
			vector<Entity> locEntities;
			if (line.size() > 7) {
				vector<string> lineItems = splitR(line[7], ',');			//gets the string contiaining the items id

				for (int i = 0; i < lineItems.size(); i++)						//Item id is the same as its index within the items vector
					locItems.push_back(items[atoi(lineItems[i].c_str())]);		//add item from items vector to a vector for its location	
			}

			if (line.size() > 8) {
				vector<string> lineEntities = splitR(line[8], ',');
				for (int i = 0; i < lineEntities.size(); i++) 
					locEntities.push_back(entities[atoi(lineEntities[i].c_str())]);
			}

			vector<string> directions = splitR(line[6], ',');				//store connections as a string, once all the locations have been created they will be linked properly
			vector<string> idents = splitR(line[2], ',');
			locations.push_back(Location(idents, line[3], line[4], line[5], locItems, directions, stoi(line[1].c_str()), locEntities));
			break;
		}
	}

	for (int i = locations.size() - 1; i >= 0; i--) {
		vector<Location> connections;

		for (int j = locations[i].directions.size() - 1; j >= 0; j--) 
			connections.push_back(locations[locations[i].directions[j][0] - '0']);	//gets the location which corresponds to the index stored in the current location's directions vector
																					//also adds the direction  as the second pair (this will be used as the index in the map)
		locations[i].addConnections(connections);									//add the map, which stores the locations which connect to the current location
	}

	startLocation = locations[0];
}


vector<Component*> Gameplay::CreateComponents(vector<string> _comps, vector<Item> _items)
{
	vector<Component *> components;
	for (int i = 0; i < _comps.size(); i++) {
		switch (_comps[i][0]) {
		case 'I':
		{
			vector<string> inventoryString = splitR(_comps[i], '-');
			Inventory* inv = new Inventory(); //needs to stay in scope as only a pointer can be passed
			for (int j = 1; j < inventoryString.size(); j++) 
				inv->PutItem(_items[stoi(inventoryString[j])]);
			
			components.push_back(inv);
			break;
		}
		case 'C':
		{
			vector<string> combat = splitR(_comps[i], '-');
			components.push_back(new Combat(stoi(combat[1]), stoi(combat[2])));
			break;
		}
		case 'O':
			vector<string> openable = splitR(_comps[i], '-');
			components.push_back(new Openable(stoi(openable[1])));
			break;
		}
	}
	return components;
}

void Gameplay::NewHighScore() { 
	cout << "HIGHSCORE" << endl <<"Enter Name: ";
	string name;
	cin >> name;
}
void Gameplay::start()
{
	CommandManager com;
	Location prevLocation = startLocation;
	Go go;

	startLocation.printText();

	while (1) {
	
		if (!startLocation.GetEntity("enemy").Empty())		//If there is an enemy in the location
			Blackboard().messages.push_back("BLOCK");		//Post a message blocking the go command
		
		cout << "Command:>";
		string input;
		getline(cin, input);
		
		vector<string> in = splitR(input, ' ');
		
		if (in[0] == "inv") { //debug
			cout << "Player inventory: " << static_cast<Inventory*>(player.FindComponent("inventory"))->Open() << endl;
			continue;
		}

		if (go.AreYou(in[0])) {
			startLocation = startLocation.goTo(go.Execute(in, &startLocation, &player));
			if (prevLocation.Name != startLocation.Name) {
				startLocation.printText();
				cout << "Player inventory: " << static_cast<Inventory*>(player.FindComponent("inventory"))->Open() << endl;
				prevLocation = startLocation;
			}
		}
		else 
			cout << com.Execute(in, &startLocation, &player) << endl;
		
	}
}
Gameplay::~Gameplay(){}

vector<std::string> Gameplay::splitR(const std::string & s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}
void Gameplay::split(const std::string & s, char delim, back_insert_iterator<vector<string>> result)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}