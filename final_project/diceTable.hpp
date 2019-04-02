//diceTable.hpp
//
//
#ifndef DICETABLE_HPP
#define DICETABLE_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"
class DiceTable : public Space
{
private:
	std::vector<Item> diceTableItems;
	std::string description2;
	std::string description3;
public:
	void setDescription(std::string, std::string, std::string);
	std::string getDescription();
	std::vector<Item> getItemVector();
	std::string playDice();
	void addItem(Item);
	void removeItem();
	DiceTable();
	DiceTable(int, int);
	friend class QuadLinkedList;
};

#endif