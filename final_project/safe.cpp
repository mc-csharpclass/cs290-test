/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   safe.cpp has functions setLeftIsOpen, setRightIsOpen, inputCode,
**				 setDescription, getDescription, getIsOpen, addItem, removeItem,
**				 getItemVector.
**				 input code returns an int that is used in a switch statement in main
**				 based on the code input by player and the state of the safe, for example:
**				 if the doors are opened, if the code has already been used ect.
**				 
*****************************************************************************/
//safe.cpp
//
//
#include "safe.hpp"
#include "item.hpp"
#include <iostream>

int Safe::validateInput(int min, int max, std::string prompt)
{
	bool isInvalid = true;
	int validNum = 0;
	std::string userInput;

	while (isInvalid)
	{
		std::cout << prompt << " ";
		std::getline(std::cin, userInput);

		std::stringstream strBuffer(userInput);

		if (strBuffer >> validNum && strBuffer.eof())
		{
			if (validNum >= min && validNum <= max)
			{
				isInvalid = false;
			}
		}
	}

	return validNum;
}

//void Safe::inputCode(std::vector<Item> &playerList)
void Safe::setLeftIsOpen(bool setLeftIsOpen)
{
	leftIsOpen = setLeftIsOpen;
}

void Safe::setRightIsOpen(bool setRightIsOpen)
{
	rightIsOpen = setRightIsOpen;
}

int Safe::inputCode()
{	
	if (leftIsOpen == true && rightIsOpen == true)
	{
		std::cout << "\nI think I'm finished with this safe.\n";
		return 1;

	}
	else if (leftIsOpen == false || rightIsOpen == false)
	{
		//std::cout << "\nPlease enter a 3 digit code: ";

		int getCode;
		//std::cin >> getCode;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		getCode = validateInput(000, 999, "\nPlease enter a 3 digit code: ");
		if (getCode == 516 && leftIsOpen == false)
		{
			std::cout << "\nThe left door opened.  I take what's inside.\n";
			return 2;	
		}
		else if ((getCode == 516 && leftIsOpen == true) || (getCode == 247 && rightIsOpen == true))
		{
			std::cout << "\nI already used that code.  Maybe there is another one...\n";
			return 1;
		}
		else if (getCode == 247 && rightIsOpen == false)
		{
			std::cout << "\nThe right door opened.  I take what's inside.\n";
			return 3;
		}
		else
		{
			std::cout << "\nThat code dosn't seem to have worked.";
			return 1;
		}
	}
}
void Safe::setDescription(std::string setDescription, std::string setDescription2, std::string setDescription3, std::string setDescription4)
{
	description = setDescription;
	description2 = setDescription2;
	description3 = setDescription3;
	description4 = setDescription4;
}

std::string Safe::getDescription()
{
	if (leftIsOpen == false && rightIsOpen == false)
	{
		return description;
	}
	else if (leftIsOpen == false && rightIsOpen == true)
	{
		return description2;
	}
	else if (leftIsOpen == true && rightIsOpen == false)
	{
		return description3;
	}
	else
	{
		return description4;
	}
}

bool Safe::getIsOpen()
{
	return isOpen;
}

void Safe::setIsOpen(bool setIsOpen)
{
	isOpen = setIsOpen;
}

void Safe::addItem(Item addItem)
{
	safeItems.push_back(addItem);
}

void Safe::removeItem()
{
	std::cout << "test safe remove item: \n";
	safeItems.pop_back();
}

std::vector<Item> Safe::getItemVector()
{
	return safeItems;
}
Safe::Safe()
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = 0;
	column = 0;
	description = " ";
	playerHere = false;
	mapKey ="SFE";
	//	itemList items;
}
Safe::Safe(int setRow, int setColumn)
{
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	row = setRow;
	column = setColumn;
	description = " ";
	playerHere = false;
	mapKey = "SFE";
}