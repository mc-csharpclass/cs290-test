/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   space.cpp is a virtual class that all other types of spaces are
**				 derived from.  It has too many functions to list but they are
**				 pretty much all overridden by the derived classes.  It also has
**				 a copy constructor.
*****************************************************************************/
//space.cpp
//
//
//
#include "space.hpp"
#include "item.hpp"

//void Space::inputCode(std::vector<Item> playerList)
//{
//
//}
void Space::setLocked(bool)
{

}
bool Space::getLocked()
{

}

void Space::setLeftIsOpen(bool setLeftIsOpen)
{
	//leftIsOpen = setLeftIsOpen;
}

void Space::setRightIsOpen(bool setRightIsOpen)
{
	//rightIsOpen = setRightIsOpen;
}

int Space::inputCode()
{
	return 0;
}

std::string Space::playDice()
{

}

bool Space::getCanPutItem()
{
	return canPutItem;
}

void Space::setCanPutItem(bool setCanPutItem)
{
	canPutItem = setCanPutItem;
}

bool Space::getIsOpen()
{

}

std::vector<Item> Space::getItemVector()
{
	
}

void Space::addItem(Item addItem)
{
	
}

void Space::removeItem()
{
	
}

bool Space::getIsItem()
{
	return isItem;
}

void Space::setIsItem(bool setIsItem)
{
	isItem = setIsItem;
}

void Space::setCanOpen(bool setCanOpen)
{
	canOpen = setCanOpen;
}

bool Space::getCanOpen()
{
	return canOpen;
}

void Space::setIsOpen(bool setIsOpen)
{
	canOpen = setIsOpen;
}

void Space::setDescription(std::string setDescription)
{
	description = setDescription;
}

std::string Space::showDescription()
{
	return description;
}

std::string Space::getMapKey()
{
	return this->mapKey;
}

std::string Space::getMapKey() const
{
	return this->mapKey;
}

Space& Space::operator=(const Space &RHS)
{
	this->row = RHS.getRow();
	this->column = RHS.getColumn();
	this->mapKey = RHS.getMapKey();
	this->description = RHS.getDescription();
	this->playerHere = RHS.getPlayerHere();
	this->canOpen = RHS.canOpen;
	//this->isItem = RHS.isItem;
	return *this;
}

int Space::getRow()
{
	return this->row;
}

int Space::getColumn()
{
	return this->column;
}

int Space::getColumn() const
{
	return this->column;
}

int Space::getRow() const
{
	return this->row;
}

bool Space::getPlayerHere()
{
	return this->playerHere;
}

bool Space::getPlayerHere() const
{
	return this->playerHere;
}

std::string Space::getDescription()
{
	return this->description;
}

std::string Space::getDescription(int someInt)
{
	return this->description;
}

std::string Space::getDescription() const
{
	return this->description;
}

void Space::setNorth(Space* setNorth)
{
	north = setNorth;
}

Space* Space::getNorth()
{
	return north;
}

void Space::setSouth(Space* setSouth)
{
	south = setSouth;
}

Space* Space::getSouth()
{
	return south;
}

void Space::setEast(Space* setEast)
{
	east = setEast;
}
Space* Space::getEast()
{
	return east;
}

void Space::setWest(Space* setWest)
{
	west = setWest;
}

Space* Space::getWest()
{
	return west;
}

Space::Space()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "_";
	canOpen = false;
	isItem = false;
//	itemList items;
}
Space::Space(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	canOpen = false;
	isItem = false;
	mapKey = "_";
}