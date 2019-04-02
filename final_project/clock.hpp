//clock.hpp
//
//
//
#ifndef CLOCK_HPP
#define CLOCK_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"
class Clock : public Space
{
	private:
		std::string description2;
	public:
		void setDescription(std::string, std::string);
		std::string getDescription();
		Clock();
		Clock(int, int);
		friend class QuadLinkedList;
};

#endif