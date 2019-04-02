/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   item.cpp has functions getName, getDescription and constructors
*****************************************************************************/
//itm.cpp
//
//
//

#include "item.hpp"

std::string Item::getName()
{
	return name;
}

std::string Item::getDescription()
{
	return description;
}

Item::Item()
{
	name = "name ";
	description = "description: ";
}

Item::Item(std::string setName, std::string setDescription)
{
	name = setName;
	description = setDescription;
}