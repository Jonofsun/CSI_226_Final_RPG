#include "Game.h"

Game::Game() 
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";
}
Game::~Game()
{

}

//Functions
void Game::initGame() 
{

	//Load Save through json password '1234'
	createNewCharacter();
	
}
void Game::mainMenu() 
{
	std::cout << "= Main Menu =" << std::endl << std::endl;
	std::cout << "1: Travel" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Level Up" << std::endl;
	std::cout << "4: Rest" << std::endl;
	std::cout << "5: Character Stats" << std::endl;
	std::cout << "6: Create New Hero" << std::endl;
	std::cout << "7: Save" << std::endl;
	std::cout << "8: Load" << std::endl;
	std::cout << "0: Quit" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Select an option: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) 
	{
	case 0:
		playing = false;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		characters[activeCharacter].printStats();
		break;
	case 6:
		std::cin.ignore();
		createNewCharacter();
		saveCharacter();
		break;
	case 7:
		saveCharacter();
		break;
	case 8:
		loadCharacter();
		break;
	default:
		break;

	}
}
void Game::createNewCharacter() 
{
	std::string name;
	std::cout << "Enter your Name: " << std::endl;
	getline(std::cin, name);
	/*std::cin.ignore();*/

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}
void Game::saveCharacter()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open()) 
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void Game::loadCharacter()
{

}