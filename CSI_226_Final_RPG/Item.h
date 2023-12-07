#pragma once

#include<iostream>
#include<iomanip>
#include<string>

class Item // Item is an abstract class, you cant create an item by itself you have to crate weapon, armor, ect...
{
public:
	Item(std::string name = "None", int level = 0,
		int buyValue = 0,
		int sellValue = 0,
		int rarity = 0);
	virtual ~Item();

	inline std::string debugPrint() const { return this->name; }

	virtual Item* clone()const = 0; // return a item

	//Accessors
	inline const std::string& getName() const { return this->name; } // you can only make pointers to this class
	inline const int& getLevel() const { return this->level; }
	inline const int& getBuyValue() const { return this->buyValue; }
	inline const int& getSellValue() const { return this->sellValue; }
	inline const int& getRarity() const { return this->rarity; }

	//Modifiers


private:
	std::string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;

};

