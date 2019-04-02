//quadLinkedList.hpp
//
//
//

#ifndef QUADLINKEDLIST_HPP
#define QUADLINKEDLIST_HPP

#include "space.hpp"
#include "item.hpp"

class QuadLinkedList
{
	private:
		Space* location;
		std::vector<Item> pocket;
		bool hasStem;
		bool hasHandle;
	public:
		bool getHasStem();
		bool getHasHandle();
		void setHasStem(bool);
		void setHasHandle(bool);
		std::vector<Item>& getItemVector();
		void addItem(Item);
		void removeItem();
		void moveNorth();
		void moveSouth();
		void moveEast();
		void moveWest();
		void setLocation(Space*);
		Space* getLocation();
		QuadLinkedList();
		QuadLinkedList(Space*);
};

#endif