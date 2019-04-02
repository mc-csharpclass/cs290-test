//quadLinkedNode.cpp
//
//
#include "quadLinkedNode.hpp"
#include "space.hpp"
QuadLinkedNode::QuadLinkedNode()
{
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;
	spaceType = Space*;
}

QuadLinkedNode::QuadLinkedNode(Space* setNorth, Space* setSouth, Space* setEast, Space* setWest, Space* setSpaceType)
{
	north = setNorth;
	south = setSouth;
	east = setEast;
	west = setWest;
	spaceType = setSpaceType;
}