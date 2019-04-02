//space.hpp
//
//
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <vector>
#include "itemList.hpp"
#include "item.hpp"
//#include "quadLinkedList.hpp"

class Space
{
	protected:
		Space* north;
		Space* south;
		Space* west;
		Space* east;
		int	row;
		int column;
		std::string description;
		bool playerHere;
		bool canOpen;
		bool isItem;
		bool canPutItem;
		std::string mapKey;
		//itemList items;
	public:
		//virtual void inputCode(std::vector<Item>);
		virtual void setLeftIsOpen(bool);
		virtual void setRightIsOpen(bool);
		virtual void setLocked(bool);
		virtual bool getLocked();
		virtual int inputCode();
		virtual std::string playDice();
		bool getCanPutItem();
		void setCanPutItem(bool);
		virtual std::vector<Item> getItemVector();
		virtual void addItem(Item);
		virtual void removeItem();
		bool getIsItem();
		void setIsItem(bool);
		virtual bool getIsOpen();
		bool getCanOpen();
		void setCanOpen(bool);
		virtual void setIsOpen(bool);
		void setDescription(std::string);
		std::string showDescription();
		std::string getMapKey();
		std::string getMapKey() const;
		void setNorth(Space*);
		Space* getNorth();
		void setSouth(Space*);
		Space* getSouth();
		void setEast(Space*);
		Space* getEast();
		void setWest(Space*);
		Space* getWest();
		int getRow();
		int getRow() const;
		int getColumn();
		int getColumn() const;
		bool getPlayerHere();
		bool getPlayerHere() const;
		virtual std::string getDescription();
		virtual std::string getDescription(int);
		std::string getDescription() const;
		Space();
		Space(int, int);
		Space& operator=(const Space &RHS);
		friend class QuadLinkedList;
};

#endif