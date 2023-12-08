#pragma once
#include<iostream>
#include<ctime>
#include<vector> // undifind array - dynamic
#include<fstream> // file input - output operations
#include"Functions.h"
#include"Character.h"
#include"Event.h"



class Game
{
public:
	Game();
	virtual ~Game(); // you can call a virtual function for an object to overide and execute the derived class’s version of the method.

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void saveCharacter();
	void loadCharacter();
	void Travel();

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

