#pragma once
#include"Item.h"

class Armor :
	public Item
{
public:
	Armor(int type = 0, int defence = 0,
		std::string name = "None", int level = 0, int buyValue = 0,
		int sellValue = 0, int rarity = 0);
	virtual ~Armor();

	//Pure virtural
	virtual Armor* clone()const; // depeding on if its an armor or weapon it will clone itself in inventory 

	std::string toString();

private:
	int type;
	int defence;

};

