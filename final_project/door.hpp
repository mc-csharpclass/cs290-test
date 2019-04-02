//door.hpp
//
//
//
#ifndef DOOR_HPP
#define DOOR_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"
class Door : public Space
{
private:
	bool locked;
	std::string description2;
public:
	bool getLocked();
	void setLocked(bool);
	void setDescription(std::string, std::string);
	std::string getDescription();
	Door();
	Door(int, int);
	friend class QuadLinkedList;
};

#endif