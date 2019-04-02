//item.hpp
//
//
//

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item
{
	private:
		std::string name;
		std::string description;
	public:
		std::string getName();
		std::string getDescription();
		Item();
		Item(std::string, std::string);
};

#endif