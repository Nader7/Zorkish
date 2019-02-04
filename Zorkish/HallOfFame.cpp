#include "HallOfFame.h"

HallOfFame::HallOfFame(){}

HallOfFame::~HallOfFame(){}

void HallOfFame::start()
{
	//test data
	cout << "Zorkish::Hall Of Fame" << endl <<
		"--------------------------------------------------------" << endl <<
		"Top 10 Zorkish Adventure Champions" << endl <<
		"1. Fred, Mountain World, 5000" << endl <<
		"2. Mary, Mountain World, 4000" << endl <<
		"3. Joe, Water World, 3000" << endl <<
		"4. Henry, Mountain World, 2000" << endl <<
		"5. Susan, Mountain World, 1000" << endl <<
		"6. Alfred, Water World, 900" << endl <<
		"7. Clark, Mountain World, 800" << endl <<
		"8. Harold, Mountain World, 500" << endl <<
		"9. Julie, Water World, 300" << endl <<
		"10. Bill, Box World, -5" << endl;

	system("pause");
}

void HallOfFame::AddHighScore(int score, string name, string world)
{
	// add new highscore
	cout << "HIGHSCORE: " << score << ", Name: " << name << ", World: " << world;
}

