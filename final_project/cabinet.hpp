//cabinet.hpp
//
//
//
#ifndef CABINET_HPP
#define CABINET_HPP

#include <string>
#include <vector>
#include "itemList.hpp"
#include "space.hpp"
#include "item.hpp"

class Cabinet : public Space
{
	private:
		std::vector<Item> cabinetItems;
		bool isOpen;
		bool canOpen;
		std::string description2;
		std::string description3;
	public:
		void setDescription(std::string, std::string, std::string);
		std::string getDescription();
		bool getIsOpen();
		void setIsOpen(bool);
		std::vector<Item> getItemVector();
		void addItem(Item);
		void removeItem();
		Cabinet();
		Cabinet(int, int);
		friend class QuadLinkedList;
};

#endif