//safe.hpp
//
//
//
#ifndef SAFE_HPP
#define SAFE_HPP
#include <string>
#include <sstream>
#include "itemList.hpp"
#include "space.hpp"
#include "quadLinkedList.hpp"

class Safe : public Space
{
private:
	std::vector<Item> safeItems;
	bool leftIsOpen;
	bool rightIsOpen;
	bool isOpen;
	bool canOpen;
	std::string description2;
	std::string description3;
	std::string description4;
public:
	//void inputCode(std::vector<Item>&);
	int validateInput(int, int, std::string);
	void setLeftIsOpen(bool);
	void setRightIsOpen(bool);
	int inputCode();
	void setDescription(std::string, std::string, std::string, std::string);
	std::string getDescription();
	bool getIsOpen();
	void setIsOpen(bool);
	std::vector<Item> getItemVector();
	void addItem(Item);
	void removeItem();
	Safe();
	Safe(int, int);
	friend class QuadLinkedList;
};

#endif