/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   clock.cpp has functions setDescripiton, getDescription, and
**				 constructors.
*****************************************************************************/
//clock.cpp
//
//
#include "clock.hpp"

void Clock::setDescription(std::string setDescription1, std::string setDescription2)
{
	description = setDescription1;
	description2 = setDescription2;
}

std::string Clock::getDescription()
{
	return description + description2;
}

Clock::Clock()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "CLK";
	//	itemList items;
}
Clock::Clock(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "CLK";
}