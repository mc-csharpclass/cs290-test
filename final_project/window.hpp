//window.hpp
//
//
//
#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <string>
#include "itemList.hpp"
#include "space.hpp"
class Window : public Space
{
private:
	std::string description2;
	std::string description3;
public:
	void setDescription(std::string, std::string, std::string);
	std::string getDescription(int);
	Window();
	Window(int, int);
	friend class QuadLinkedList;
};

#endif
