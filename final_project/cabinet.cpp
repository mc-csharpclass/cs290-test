/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   cabinet.cpp has functions setDescription, getDescription, setIsOpen,
**				 getIsOpen, addItem, removeItem, and constructors.
*****************************************************************************/
//cabinet.cpp
//
//
//
#include "cabinet.hpp"
#include "item.hpp"
#include <iostream>
void Cabinet::setDescription(std::string setDescription, std::string setDescription2, std::string setDescription3)
{
	description = setDescription;
	description2 = setDescription2;
	description3 = setDescription3;
}

std::string Cabinet::getDescription()
{
	if (isOpen == false)
	{
		return description;
	}
	else if(this->cabinetItems.empty())
	{
		return description2;
	}
	else
	{
		return description2 + description3;
	}
}

bool Cabinet::getIsOpen()
{
	return isOpen;
}

void Cabinet::setIsOpen(bool setIsOpen)
{
	isOpen = setIsOpen;
}

void Cabinet::addItem(Item addItem)
{
	cabinetItems.push_back(addItem);
}

void Cabinet::removeItem()
{
	cabinetItems.pop_back();
}

std::vector<Item> Cabinet::getItemVector()
{
	return cabinetItems;
}

Cabinet::Cabinet()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	canOpen = true;
	mapKey = "CAB";
	//	itemList items;
}
Cabinet::Cabinet(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	canOpen = true;
	mapKey = "CAB";
}