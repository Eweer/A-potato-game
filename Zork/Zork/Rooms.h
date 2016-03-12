#ifndef __ROOMS_H__
#define __ROOMS_H__

#include "Exits.h"
#include "Globals.h"
#include <string>


class Rooms
{
private:
	Exits* exit;
	std::string description;
	location loc;

public:
	Rooms();
	void CreateRoom(location loc);
	location move(action a);
	std::string GetDescription();
	~Rooms();
};

#endif //__ROOMS_H__