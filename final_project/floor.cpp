/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   floor.cpp is the basic space with nothing special that is
**				 derived from space class
*****************************************************************************/
//floor.cpp
//
//
//
#include "floor.hpp"
Floor::Floor()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "___";
	//	itemList items;
}
Floor::Floor(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "___";
}