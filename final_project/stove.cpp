/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   stove.cpp has functions getIsOpen, setIsOpen, setDescription, 
**				 getDescription, addItem, removeItem, getItemVector and constructors.
*****************************************************************************/
//stove.cpp
//
//
#include "stove.hpp"

bool Stove::getIsOpen()
{
	return isOpen;
}

void Stove::setIsOpen(bool setIsOpen)
{
	isOpen = setIsOpen;
}

void Stove::setDescription(std::string setDescription, std::string setDescription2, std::string setDescription3)
{
	description = setDescription;
	description2 = setDescription2;
	description3 = setDescription3;
}

std::string Stove::getDescription()
{
	if (isOpen == false)
	{
		return description;
	}
	else if (this->stoveItems.empty())
	{
		return description2;
	}
	else
	{
		return description2 + description3;
	}
}

void Stove::addItem(Item addItem)
{
	stoveItems.push_back(addItem);
}

void Stove::removeItem()
{
	stoveItems.pop_back();
}

std::vector<Item> Stove::getItemVector()
{
	return stoveItems;
}

Stove::Stove()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "STV";
	//	itemList items;
}
Stove::Stove(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "STV";
}