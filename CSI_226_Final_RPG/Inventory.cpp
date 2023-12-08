#include "Inventory.h"

Inventory::Inventory() 
{
	this->cap = 5;
	this->numOfItems = 0;
	this->itemArr = new Item*[cap];
	this->initialize(); // you cannot delete null pointer without a crash
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numOfItems; i++)
	{
		delete this->itemArr[i];

	}
	delete[] itemArr;
}

Inventory::Inventory(const Inventory& obj) // copy contructer, only called once / shallow copy
{
	this->cap = obj.cap;
	this->numOfItems = obj.numOfItems;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->numOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(this->numOfItems);
}

Item& Inventory::operator[](const int index) // operator is a GET function; overloading index operator
{
	if (index < 0 || index >= this->numOfItems) throw("Bad Index"); // within scope of array

	return *this->itemArr[index]; // de-reference to not return the point but return the object
}

void Inventory::expand() // Expanding a pointer pointer ** array 
{
	this->cap *= 2;

	Item **tempArr = new Item*[this->cap]; // make a copy of the item array

	for (size_t i = 0; i < this->numOfItems; i++)
	{
		tempArr[i] = this->itemArr[i]; // copy old memory
	}
	
	delete[] this->itemArr; // delete old memory

	this->itemArr = tempArr; // set the new item array

	this->initialize(this->numOfItems);
}
void Inventory::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr; // runs through the lenth of the array and fills empty with null pointers
	}
}
void Inventory::addItem(const Item& item)
{
	if (this->numOfItems >= this->cap) 
	{
		expand();
	}
	itemArr[this->numOfItems++] = item.clone(); // i would need a check in here on what item was being added if i didnt use a pointer
}
void Inventory::removeItem(int index)
{

}
