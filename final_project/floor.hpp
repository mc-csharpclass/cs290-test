//floor.hpp
//
//
#ifndef FLOOR_HPP
#define FLOOR_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"
class Floor : public Space
{
private:

public:
	Floor();
	Floor(int, int);
	friend class QuadLinkedList;
};

#endif