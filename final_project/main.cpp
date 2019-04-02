/****************************************************************************
** Program name: Final Project
** Author:       Michael Czapary
** Date:         3-16-2019
** Dscription:   main.cpp sets up the game spaces and items.  It also creates the
**				 map and takes input for the players actions
*****************************************************************************/
//main.cpp
//
//
#include <iostream>
#include <algorithm>
#include "cabinet.hpp"
#include "clock.hpp"
#include "diceTable.hpp"
#include "door.hpp"
#include "safe.hpp"
#include "space.hpp"
#include "stove.hpp"
#include "floor.hpp"
#include "quadLinkedList.hpp"
#include "window.hpp"

int main()
{
	char testChar = 'n'; //user input variable
	int RoomRow = 4;
	int RoomColumn = 3;
	int turnCount = 0;
	//create the game spaces
	Cabinet cabinet(0, 0);	
	Clock clock(0, 1);
	Floor zeroTwo(0, 2);
	Floor oneZero(1, 0);
	Floor oneOne(1, 1);
	Door door(1, 2);
	Window window(2, 0);
	Floor twoOne(2, 1);
	Floor twoTwo(2, 2);
	Safe safe(3, 0);
	DiceTable diceTable(3, 1);
	Stove stove(3, 2);
	//create the player
	QuadLinkedList player(&window);
	//set up cabinet and items
	std::string noteName = "Note";
	std::string noteDescription = "You are locked in this room.  Find the key to escape";

	std::string cabinetClosed = "Before you is a tall cabinet with two large doors.";
	std::string cabinetOpened = "Inside the cabinet there is a single shelf."; 
	std::string cabinetNote = " Sitting on the shelf you see a small folded piece of paper.";
	
	Item note(noteName, noteDescription);
	cabinet.setDescription(cabinetClosed, cabinetOpened, cabinetNote);
	cabinet.addItem(note);
	cabinet.setCanOpen(true);
	cabinet.setIsItem(true);
	cabinet.setIsOpen(false);
	cabinet.setCanPutItem(true);

	//set up clock
	std::string clockDescription1 = "There is a blinking digital clock on the wall.  The time reads 91:2.\n";
	std::string clockDescription2 = "It seems that the time on the clock is not changing.  It might be broken.\n";
	clock.setDescription(clockDescription1, clockDescription2);

	//set up stove and items
	std::string diceName = "Dice";
	std::string diceDescription = "There are two six sided dice.  When you pick them up they feel a little heavier than normal dice.";

	std::string stoveClosed = "There is an old wood burning stove infront of you with a latch to keep the door closed.";
	std::string stoveOpened = "The inside of the stove is black from soot.  There is a bowl shaped place to hold wood.";
	std::string stoveDice = " Sitting in the bowl there are two dice.";

	Item dice(diceName, diceDescription);
	stove.setDescription(stoveClosed, stoveOpened, stoveDice);
	stove.addItem(dice);
	stove.setCanOpen(true);
	stove.setIsItem(true);
	stove.setIsOpen(false);

	//set up table and items
	std::string tableNoteName = "Dice rules";
	std::string tableNoteDescription = "Roll the dice three times to get your score.  Higest score wins.";
	
	std::string tableNote = "There is a dice table here.  There is a note on top of the table.";
	std::string tableEmpty = "There is a dice table here.  If I guess if I had some dice I could play.";	
	std::string tableDice = "There are two dice sitting on the dice table.  Maybe I should give them a roll.";
	
	Item diceTableRules(tableNoteName, tableNoteDescription);
	diceTable.setDescription(tableNote, tableEmpty, tableDice);
	diceTable.addItem(diceTableRules);
	diceTable.setCanOpen(false);
	diceTable.setIsItem(true);
	diceTable.setCanPutItem(true);

	//set up safe and items
	std::string keyHandleName = "Key handle";
	std::string keyHandleDescription = "There is a round object that looks like the handle for a key. It looks like it could attach it to something else...\n";

	std::string keyStemName = "Key stem";
	std::string keyStemDescription = "There is the stem of a key.  It looks like I could attach it to something...\n";

	Item keyHandle(keyHandleName, keyHandleDescription);
	Item keyStem(keyStemName, keyStemDescription);

	std::string safeLocked = "There is an electronic safe.  It looks like there is a place to input a code.";
	std::string safeRightOpen = "The right side door of the safe is open, but the left is still closed.  I wonder if there is something behind it...";
	std::string safeLeftOpen = "The left side door of the safe is open, but the right is still closed.  I wonder if there is something behind it ...";
	std::string safeOpened = "Both of the safe doors are opened.";

	safe.setDescription(safeLocked, safeRightOpen, safeLeftOpen, safeOpened);
	safe.addItem(keyHandle);
	safe.addItem(keyStem);
	safe.setCanOpen(true);
	safe.setIsItem(true);

	//set up door
	std::string doorLocked = "On the wall you see a huge metal door.  You push against it but it doesn't budge.  You notice there is a key hole though.";
	std::string doorUnlocked = "With quite a bit of effort you force the door open and walk through.";

	door.setDescription(doorLocked, doorUnlocked);	
	door.setIsItem(false);
	door.setCanOpen(true);
	door.setLocked(true);

	//set up window
	std::string windowEarly = "On the wall there is round window lined with large bolts.  It reminds you of a window\n";
	std::string windowEarly2 = "on a ship. You look though the window but it is too dark to see much of anything.";
	std::string windowLate = "Water continues to pour through the crack in the window.  You fear soon the room will be filled with water!";

	window.setDescription(windowEarly, windowEarly2, windowLate);
	window.setIsItem(false);

	//set up floor space
	std::string floorDescription = "There isn't anything interesting here.";

	zeroTwo.setDescription(floorDescription);
	oneZero.setDescription(floorDescription);
	oneOne.setDescription(floorDescription);	
	twoOne.setDescription(floorDescription);
	twoTwo.setDescription(floorDescription);

	//link the game spaces
	cabinet.setNorth(nullptr);
	cabinet.setSouth(&oneZero);
	cabinet.setEast(&clock);
	cabinet.setWest(nullptr);

	clock.setNorth(nullptr);
	clock.setSouth(&oneOne);
	clock.setEast(&zeroTwo);
	clock.setWest(&cabinet);

	zeroTwo.setNorth(nullptr);
	zeroTwo.setSouth(&door);
	zeroTwo.setEast(nullptr);
	zeroTwo.setWest(&clock);

	window.setNorth(nullptr);
	window.setSouth(&door);
	window.setEast(nullptr);
	window.setWest(&clock);

	oneZero.setNorth(&cabinet);
	oneZero.setSouth(&window);
	oneZero.setEast(&oneOne);
	oneZero.setWest(nullptr);

	oneOne.setNorth(&clock);
	oneOne.setSouth(&twoOne);
	oneOne.setEast(&door);
	oneOne.setWest(&oneZero);

	door.setNorth(&zeroTwo);
	door.setSouth(&twoTwo);
	door.setEast(nullptr);
	door.setWest(&oneOne);

	window.setNorth(&oneZero);
	window.setSouth(&safe);
	window.setEast(&twoOne);
	window.setWest(nullptr);

	twoOne.setNorth(&oneOne);
	twoOne.setSouth(&diceTable);
	twoOne.setEast(&twoTwo);
	twoOne.setWest(&window);

	twoTwo.setNorth(&door);
	twoTwo.setSouth(&stove);
	twoTwo.setWest(&twoOne);
	twoTwo.setEast(nullptr);

	safe.setNorth(&window);
	safe.setSouth(nullptr);
	safe.setEast(&diceTable);
	safe.setWest(nullptr);

	diceTable.setNorth(&twoOne);
	diceTable.setSouth(nullptr);
	diceTable.setEast(&stove);
	diceTable.setWest(&safe);

	stove.setNorth(&twoTwo);
	stove.setSouth(nullptr);
	stove.setEast(nullptr);
	stove.setWest(&diceTable);

	//create pointers to space for the map
	Space** theRoom = new Space*[RoomRow];
	for (int r = 0; r < RoomRow; ++r)
	{
		theRoom[r] = new Space[RoomColumn];

	}
	
	theRoom[0][0] = cabinet;
	theRoom[0][1] = clock;	
	theRoom[0][2] = zeroTwo;
	
	theRoom[1][0] = oneZero;	
	theRoom[1][1] = oneOne;	
	theRoom[1][2] = door;
	
	theRoom[2][0] = window;	
	theRoom[2][1] = twoOne;	
	theRoom[2][2] = twoTwo;
	
	theRoom[3][0] = safe;	
	theRoom[3][1] = diceTable;	
	theRoom[3][2] = stove;

	//generate an inital map
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			std::cout << theRoom[r][c].getMapKey() << " ";
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << "Map Key:\nCAB = Cabinet, CLK = Clock, DOR = Door\nWIN = window\n"
		<< "___ = floor, SFE = Safe, TBL = Dice Table, STV = Stove\n";

	std::cout << "\nYour current location: " << player.getLocation()->getMapKey()
		<< " " << player.getLocation()->getRow() << ","
		<< player.getLocation()->getColumn() << std::endl << std::endl;

	std::cout << "You wake up in a small room with a headache.  The room is dim but you can still\n"		
		<< "see well enough. Looking around you notice a cabinet and a clock to the north, a\n" 
		<< "door to the east, a window to the west, and a safe, a table and a stove to the\n" 
		<< "south.  You aren't sure why but you feel like checking out the cabinet would\n"
		<< "be a good idea.\n\n";

	while (testChar != 'x')
	{
		turnCount++;
		if (turnCount == 40)
		{
			std::cout << "Suddenly you hear a loud noise from the window.  You look over and see\n"
				<< "a crack slowly spider webbing its way across the window.  Then you notice that\n"
				<< "there is water flowing through the crack. You wonder how long it will take\n"
				<< "to flood the entire room...\n\n";
		}
		std::cout << "\n\nn = move north \ns = move south \ne = move east \nw = move west \n"
			<< "d = get description of your area \no = open \nt = take an item\n"
			<< "p = put an item down \nl = play \nc = check items in your pocket \nm = look at the map\n"
			<< "x = exit the game\n";
		std::cout << "Input n, s, e, w, d, o, t, p, l, c, m, or x: ";
		std::cin >> testChar;
		while (testChar != 'n' && testChar != 's' && testChar != 'e' && testChar != 'w' && testChar != 'd' &&
			testChar != 'o' && testChar != 't' && testChar != 'p' && testChar != 'l' && testChar != 'c' &&
			testChar != 'm' && testChar != 'x')
		{
			std::cout << "I'm not sure what you want me to do...\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> testChar;
		}
		std::cout << "\n\n############################################################\n\n";
		//movement keys
		if (testChar == 'n')
		{
			player.moveNorth();
		}
		else if (testChar == 's')
		{
			player.moveSouth();
		}
		else if (testChar == 'w')
		{
			player.moveWest();
		}
		else if (testChar == 'e')
		{
			player.moveEast();
		}
		//description command
		else if (testChar == 'd')
		{
			if (player.getLocation()->getMapKey() == "WIN")
			{
				std::cout << std::endl << player.getLocation()->getDescription(turnCount) << std::endl;
			}
			else
			{
				std::cout << std::endl << player.getLocation()->getDescription() << std::endl;
			}
		}
		//open command
		else if (testChar == 'o')
		{
			if (player.getLocation()->getCanOpen() == false)
			{
				std::cout << "There is nothing to open.\n";
			}
			else if (player.getLocation()->getCanOpen() == true)
			{
				if (player.getLocation()->getMapKey() == "SFE")
				{
					int code = player.getLocation()->inputCode();
					switch (code)
					{
					case 1: break;
					case 2:
					{
						Item temp = player.getLocation()->getItemVector().back();
						std::cout << temp.getName() << std::endl;
						player.addItem(temp);
	
						player.getLocation()->removeItem();
						player.getLocation()->setLeftIsOpen(true);
						player.setHasStem(true);
						break;
					}
					case 3:
					{
						Item temp = player.getLocation()->getItemVector().back();
						std::cout << temp.getName() << std::endl;
						player.addItem(temp);
					
						player.getLocation()->removeItem();
						player.getLocation()->setRightIsOpen(true);
						player.setHasHandle(true);
						break;
					}
					default:
						break;
					}
					if (player.getHasStem() == true && player.getHasHandle() == true)
					{
						std::wcout << "\nI guess I'll assemble this key at the door.\n";
					}
				}
				else if (player.getLocation()->getMapKey() == "DOR")
				{
					if (player.getHasHandle() == true && player.getHasStem() == true)
					{
						std::cout << "You take the key handle and stem from you pocket and assemble the key.\n"
							<< "You slide the key into the lock and turn it.  With quite a bit of effort you push \n"
							<< " on the heavy door and it creaks open.\n";
						player.getLocation()->setLocked(false);
						testChar = 'x';
					}
					else
					{
						std::cout << "You put all of your weight behind a push but the door won't budge.\n";
					}
				}
				else
				{
					player.getLocation()->setIsOpen(true);
					std::cout << "You've opened the door.\n";
				}
			}
		}
		//take command
		else if (testChar == 't')
		{
			if (player.getLocation()->getCanOpen() == false && player.getLocation()->getIsItem() == true)
			{
				if (player.getItemVector().size() >= 4)
				{
					std::cout << "I don't have any more space in my pockets.  Maybe I can put something down.\n";
				}
				else
				{
					Item temp = player.getLocation()->getItemVector().back();
					player.getLocation()->removeItem();
					if (player.getLocation()->getItemVector().empty() == true)
					{
						player.getLocation()->setIsItem(false);
					}
					player.addItem(temp);
					std::cout << "\nYou put: " << player.getItemVector().back().getName()
						<< " into your pocket.\n\n" << std::endl;
				}
			}
			else if (player.getLocation()->getIsItem() == true)
			{
				if (player.getLocation()->getIsOpen() == true)
				{
					if (player.getItemVector().size() >= 4)
					{
						std::cout << "\nI don't have any more space in my pockets.  Maybe I can put something down.\n";
					}
					else
					{
						Item temp = player.getLocation()->getItemVector().back();
						player.getLocation()->removeItem();
						if (player.getLocation()->getItemVector().empty() == true)
						{
							player.getLocation()->setIsItem(false);
						}
						player.addItem(temp);
						std::cout << "\nYou put: " << player.getItemVector().back().getName()
							<< " into your pocket.\n\n" << std::endl;
					}
				}
				else if (player.getLocation()->getIsOpen() == false)
				{
					std::cout << "\nI should probably open it first.\n";
				}
			}
			else 
			{
				std::cout << "\nThere are no items here.\n";
			}
		}
		//put command
		else if (testChar == 'p')
		{			
				
			
			if (player.getItemVector().empty() == true)
			{
				std::cout << "My pockets are empty.";
			}
			else if (player.getLocation()->getCanPutItem() == true)
			{

				std::cout << "\nLet's see... \n";
				int count = player.getItemVector().size();
				for (int i = 0; i < count; ++i)
				{
					std::cout << i + 1 << ". " << player.getItemVector()[i].getName() << std::endl;
				}
				std::cout << "are in my pockets.\n";
				int pocketRemove;
				std::cout << "Which item should I put down (enter an int): ";
				std::cin >> pocketRemove;
				while (pocketRemove < 1 || pocketRemove > player.getItemVector().size())
				{
					std::cout << "hmm.. let me try that again...\n";						
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> pocketRemove;
					
				}				
				if (player.getItemVector()[pocketRemove - 1].getName() == "Key stem" ||
					player.getItemVector()[pocketRemove - 1].getName() == "Key handle")
				{
					std::cout << "hmm... maybe I should hold on to this.\n"
						<< "You put the item back in your pocket.\n";
				}
				else
				{
					std::cout << "I put down: " << player.getItemVector()[pocketRemove - 1].getName() << std::endl;
					
					Item temp = player.getItemVector()[pocketRemove - 1];
					player.getItemVector().erase(player.getItemVector().begin() + (pocketRemove - 1));					
					player.getLocation()->addItem(temp);					
					player.getLocation()->setIsItem(true);					
				}
			}
			else
			{
				std::cout << "\nI can't put anything here...";
			}
		}
		//play command
		else if (testChar == 'l')
		{
			if (player.getLocation()->getMapKey() == "TBL")
			{
				std::cout << player.getLocation()->playDice() << std::endl;
			}
			else
			{
				std::cout << "\nThere is nothing here to play.\n";
			}
		}
		//check pocket command (includes examine item)
		else if (testChar == 'c')
		{
			std::cout << "\nLet's see... \n";
			if (player.getItemVector().empty() == true)
			{
				std::cout << "My pockets are empty.\n";
			}
			else
			{
				int count = player.getItemVector().size();
				for (int i = 0; i < count; ++i)
				{
					std::cout << i+1 << ". " << player.getItemVector()[i].getName() << std::endl;
				}
				std::cout << "are in my pockets.\n";
				int pocketExamin;
				std::cout << "Which item should I examin (enter an int): ";
				std::cin >> pocketExamin;
				while (pocketExamin < 1 || pocketExamin > player.getItemVector().size())
				{
					std::cout << "hmm.. let me try that again...\n";
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> pocketExamin;
				}
				std::cout << player.getItemVector()[pocketExamin - 1].getName() << std::endl;
				std::cout << player.getItemVector()[pocketExamin - 1].getDescription() << std::endl;
				std::cout << "\nI put: " << player.getItemVector()[pocketExamin - 1].getName() 
					<< " back into my pocket." << std::endl;
			}
		}
		//map command
		else if (testChar == 'm')
		{
		std::cout << "\n\n\nMAP:\n\n";
			for (int r = 0; r < 4; r++)
			{
				std::cout << "    ";
				for (int c = 0; c < 3; c++)
				{
					std::cout << theRoom[r][c].getMapKey() << " ";
				}
				std::cout << std::endl << std::endl;
			}
			std::cout << "Map Key:\nCAB = Cabinet, CLK = Clock, DOR = Door\nWIN = window\n"
				<< "___ = floor, SFE = Safe, TBL = Dice Table, STV = Stove\n\n";
		}
		//display location after every turn
		std::cout << "\nYour current location: " << player.getLocation()->getMapKey() 
				  << " " << player.getLocation()->getRow() << "," 
				  << player.getLocation()->getColumn() << std::endl << std::endl;
		//game over if player is too slow
		if (turnCount >= 80)
		{
			std::cout << "The water that has been steadily filling the room is now up past your head.\n"
				<< "You swim up and gasp for air but there isn't much left.  You dive under water in\n"
				<< "a desperate final attempt to escape but its no use.  You feel a warm sensation\n"
				<< "over your body like you are lying in a comfy bed.  This sensation slowly \n"
				<< "fades to nothing... ";
			testChar = 'x';
		}
	}
	//game win message if final door was opened
	if (door.getLocked() == false)
	{
		std::cout << "As you open the door you are forced to squint by an agressivly bright light.\n"
			<< "As your eyes slowly adjust you notice 6 other people staring at you in confusion...\n\n\n"
			<< "Congradulations! You've escaped!  Thanks for playing!\n";
		std::cout << "You escaped in: " << turnCount << " turns.\n";
	}
	//game quit message displays turn count
	else
	{
		std::cout << "Thanks for playing.  Exiting the game...\n";
		std::cout << "You played for " << turnCount << " turns.\n";
	}
	//free memory
	for (int r = 0; r < RoomRow; ++r)
	{	
		delete[] theRoom[r];
		theRoom[r] = NULL;
	}
	delete[] theRoom;
	theRoom = NULL;

	return 0;
}

