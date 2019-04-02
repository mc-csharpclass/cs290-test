//stove.hpp
//
//
//
#ifndef STOVE_HPP
#define STOVE_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"

class Stove : public Space
{
private:
	std::vector<Item> stoveItems;
	bool isOpen;
	bool canOpen;
	std::string description2;
	std::string description3;
public:
	bool getIsOpen();
	void setIsOpen(bool);
	void setDescription(std::string, std::string, std::string);
	std::string getDescription();
	std::vector<Item> getItemVector();
	void addItem(Item);
	void removeItem();
	Stove();
	Stove(int, int);
	friend class QuadLinkedList;
};

#endif