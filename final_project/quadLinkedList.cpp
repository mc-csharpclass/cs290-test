/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   QuadLinkedList.cpp has many funcions.  getHasStem, getHasHandle,
**				 setHasStem, setHasHandle, getItemVector, addItem, removeItem,
**				 moveNorth, moveSouth, moveEast, moveWest, getLocation, setLocation,
**				 and constructors.  
*****************************************************************************/
//quadLinkedList.cpp
//
//
//

#include "quadLinkedList.hpp"
#include <iostream>
bool QuadLinkedList::getHasStem()
{
	return hasStem;
}

bool QuadLinkedList::getHasHandle()
{
	return hasHandle;
}

void QuadLinkedList::setHasStem(bool setHasStem)
{
	hasStem = setHasStem;
}

void QuadLinkedList::setHasHandle(bool setHasHandle)
{
	hasHandle = setHasHandle;
}

std::vector<Item>& QuadLinkedList::getItemVector()
{
	return pocket;
}

void QuadLinkedList::addItem(Item addItem)
{
	pocket.push_back(addItem);
}

void QuadLinkedList::removeItem()
{
	pocket.pop_back();
}

void QuadLinkedList::moveNorth()
{
	if (location->getNorth() == nullptr)
	{
		std::cout << "\nI can't move through a wall.\n";
	}
	else
	{
		std::cout << "\nMoving north.\n";
		location = location->getNorth();
	}
}

void QuadLinkedList::moveSouth()
{
	if (location->getSouth() == nullptr)
	{
		std::cout << "\nI can't move through a wall.\n";
	}
	else
	{
		std::cout << "\nMoving south.\n";
		location = location->getSouth();
	}
}

void QuadLinkedList::moveEast()
{
	if (location->getEast() == nullptr)
	{
		std::cout << "\nI can't move through a wall.\n";
	}
	else
	{
		std::cout << "\nMoving east.\n";
		location = location->getEast();
	}
}

void QuadLinkedList::moveWest()
{
	if (location->getWest() == nullptr)
	{
		std::cout << "\nI can't move through a wall.\n";
	}
	else
	{
		std::cout << "\nMoving west.\n";
		location = location->getWest();
	}
}

Space* QuadLinkedList::getLocation()
{
	return location;
}

void QuadLinkedList::setLocation(Space* setLocation)
{
	location = setLocation;
}

QuadLinkedList::QuadLinkedList()
{
	location = nullptr;
}

QuadLinkedList::QuadLinkedList(Space* setLocation)
{
	location = setLocation;
}

//QuadLinkedList::QuadLinkedList(int, int)
//{
//
//}