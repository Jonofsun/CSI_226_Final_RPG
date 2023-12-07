#pragma once
#include<iostream>
#include<ctime>
#include<vector> // undifind array - dynamic
#include<fstream> // file input - output operations
#include"Functions.h"
#include"Character.h"



class Game
{
public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void saveCharacter();
	void loadCharacter();

	//Accessors
	inline bool getPlaying() const { return this->playing; }
	//Modifiers
private:
	int choice;
	bool playing;

	// Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;
};

