#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"Inventory.h"
#include"Enemy.h"


class Character
{
public:
	Character();
	virtual ~Character();

	//Functions
	void initialize(const std::string name);
	void printStats() const;
	void levelUp();
	std::string getAsString()const; // save system .txt

	//Accessors
	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos; }
	inline const int& getDistanceTravelled() const { return this->destanceTravelled; }
	inline const std::string& getName() const { return this->name; } // inline to optimize data managment, const as this will not change.
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getAccuracy() const { return this->accuracy; }
	
	//Modifiers
	inline void setDistanceTravelled(const int& distance) { this->destanceTravelled = distance; }
	inline void travel() { this->destanceTravelled++; }
	inline void gainExp(const int& exp) { this->exp += exp; this->levelUp(); }

private:
	double xPos;
	double yPos;
	int destanceTravelled;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	int gold;

	std::string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoint;
	
};

