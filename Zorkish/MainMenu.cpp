#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu(){}
MainMenu::~MainMenu(){}

void MainMenu::start()
{
	bool valid = 1;
	while (valid) {
		cout << "Zorkish :: Main Menu" << endl <<
			"--------------------------------------------------------" << endl <<
			"Welcome to Zorkish Adventures" << endl <<
			"1. Select Adventure and Play" << endl <<
			"2. Hall Of Fame" << endl <<
			"3. Help" << endl <<
			"4. About" << endl <<
			"5. Quit" << endl <<
			"Select 1-5:>";
		int input;
		cin >> input;

		switch (input) {
		case 1:
			SelectAdventure();
			break;
		case 2:
			state.hall.start();
			break;
		case 3:
			Help();
			break;
		case 4:
			About();
			break;
		case 5:
			valid = 0;
			break;
		default:
			cout << "invalid input" << endl;
		}
	}
}

void MainMenu::About()
{
	cout << "Zorkish::About" << endl <<
			"--------------------------------------------------------" << endl <<
			"Written by : Michael Nader" << endl;
	system("pause");
}

void MainMenu::Help()
{
	cout << "Zorkish::Help" << endl <<
			"--------------------------------------------------------" << endl <<
			"The following commands are supported:" << endl <<
			"go" << endl <<
			"look" << endl <<
			"open" << endl <<
			"take" << endl <<
			"attack" << endl <<
			"Highscore (for testing), " << endl;
	system("pause");
}

void MainMenu::SelectAdventure()
{
	cout << "Zorkish::Select Adventure" << endl <<
			"--------------------------------------------------------" << endl << endl <<
			"Choose your adventure" << endl << endl <<
			"1. Mountain World" << endl <<
			"Select 1:>";

	cin.ignore();
	string in;
	getline(cin, in);
	
	int input = atoi(in.c_str());

	if (input > 0 && input < 2) { //only 1 world available
		state.game = Gameplay(input);
		state.game.start();
	}
}
