/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   diceTable.cpp has functions playDice, setDescription, getDescription,
**				 addItem, removeItem, getItemVector, and constructors.  
**				 playDice checks that dice are on the table and then allows you to pay.
**				 getDescription returns a description based on what is on the table.
*****************************************************************************/
//diceTable.cpp
//
//
//
#include "diceTable.hpp"
#include <iostream>

std::string DiceTable::playDice()
{
	if (diceTableItems.empty() == true)
	{
		return "\nI'll need to put an item here before I can play.\n";
	}
	else if (diceTableItems.back().getName() == "Dice")
	{
		return "\nI roll the dice three times and the results are: 2, 4, and 7.\n";
	}

	else if (diceTableItems.back().getName() != "Dice")
	{
		return "\nI won't be able to play unless only dice are on the table.\n";
	}
}

void DiceTable::setDescription(std::string setDescription, std::string setDescription2, std::string setDescription3)
{
	description = setDescription;
	description2 = setDescription2;
	description3 = setDescription3;
}

std::string DiceTable::getDescription()
{
	if (diceTableItems.empty())
	{
		return description2;
	}
	else if (diceTableItems.back().getName() == "Dice rules")
	{
		return description;
	}
	else if (diceTableItems.back().getName() == "Dice")
	{
		return description3;
	}
}

void DiceTable::addItem(Item addItem)
{
	diceTableItems.push_back(addItem);
}

void DiceTable::removeItem()
{
	diceTableItems.pop_back();
}

std::vector<Item> DiceTable::getItemVector()
{
	return diceTableItems;
}

DiceTable::DiceTable()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "TBL";
	//	itemList items;
}
DiceTable::DiceTable(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "TBL";
}