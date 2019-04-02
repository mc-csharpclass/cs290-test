/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   door.cpp has functions getLocked, setLocked, getDescription
*****************************************************************************/
//dorr.cpp
//
//
//
#include "door.hpp"
bool Door::getLocked()
{
	return locked;
}

void Door::setLocked(bool setLocked)
{
	locked = setLocked;
}

void Door::setDescription(std::string setDescription, std::string setDescription2)
{
	description = setDescription;
	description2 = setDescription2;
}

std::string Door::getDescription()
{
	return description;
}

Door::Door()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "DOR";
	//	itemList items;
}
Door::Door(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "DOR";
}