#include "Event.h"
Event::Event() 
{
	this->numOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character) 
{
	int i = rand() % this->numOfEvents;

	switch (i) 
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character);
		break;
	case 1:
		//puzlle encounter
		puzzleEncounter(character);
		break;
	case 2:
		//lore
		break;
	default:
		break;

	}
}

void Event::enemyEncounter(Character &character)
{
	//while()
}

void Event::puzzleEncounter(Character &character)
{
	/*C:\RTC_AAS-T\CSI_226\CSI_226_Final_RPG\CSI_226_Final_RPG\*/
	/*std::cin.ignore();*/
	bool completed = false;
	int userAns = 0;
	int chances = 1;

	Puzzle puzzle("Puzzles/puzzle1.txt");
	while (!completed && chances > 0) 
	{
		chances--;
		std::cout << puzzle.getAsString() << "\n";

		std::cout << "\nWhat is your Answer? " << std::endl;
		std::cin >> userAns;
		std::cout << "\n";

		if (puzzle.getCurrectAns() == userAns) 
		{
			completed = true;
			// user gets exp, continue
			character.gainExp(rand() % 20);
		}

	}
	if (completed) 
	{
		std::cout << "\nGood answer, heres some exp for your trubble. \n" << std::endl;
	}
	else
	{
		std::cout << "\nDissapointed... \n" << std::endl;
	}
}