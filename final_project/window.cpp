/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   window.cpp has functions getDescription and setDescription
*****************************************************************************/
//window.cpp
//
//
#include "window.hpp"

void Window::setDescription(std::string setDescription1, std::string setDescription2, std::string setDescription3)
{
	description = setDescription1;
	description2 = setDescription2;
	description3 = setDescription3;
}

std::string Window::getDescription(int turnCount)
{
	if (turnCount < 40)
	{
		return description + description2;
	}
	else
	{
		return description3;
	}
}

Window::Window()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey = "WIN";
	//	itemList items;
}
Window::Window(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "WIN";
}