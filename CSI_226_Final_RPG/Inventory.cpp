#include "Inventory.h"

Inventory::Inventory() 
{
	this->cap = 10;
	this->numOfItems = 0;
	this->itemArr = new Item*[cap];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];

	}
	delete[] itemArr;
}

void Inventory::expand() // Expanding a pointer pointer ** array 
{
	this->cap *= 2;

	Item **tempArr = new Item*[this->cap]; // make a copy of the item array

	for (size_t i = 0; i < this->numOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]); // copy old memory
	}
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr; // delete old memory

	this->itemArr = tempArr; // set the new item array

	this->initialize(this->numOfItems);
}
void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}
void Inventory::addItem(const Item& item)
{
	if (this->numOfItems >= this->cap) 
	{
		expand();
	}
	itemArr[this->numOfItems++] = new Item(item);
}
void Inventory::removeItem(int index)
{

}
