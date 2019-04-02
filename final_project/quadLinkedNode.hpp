//quadLinkedNode.hpp
//
//

#ifndef QUADLINKEDNODE_HPP
#define QUADLINKEDNODE_HPP

#include "space.hpp"

class QuadLinkedNode
{
	protected:
		Space* north;
		Space* south;
		Space* east;
		Space* west;
		Space* spaceType;

	public:
		QuadLinkedNode();
		QuadLinkedNode(Space*, Space*, Space*, Space*, Space*);
};

#endif