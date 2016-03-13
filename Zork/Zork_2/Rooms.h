#ifndef __ROOMS_H__
#define __ROOMS_H__

#include "Exits.h"
#include "Globals.h"
#include <string>
#include <stdio.h>


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
	void OutputDescription();
	bool CheckExit(action input);
	doors CheckDoor(char dir);
	doors CheckDoorMove(action a);
	void ChangeDoorOpenClose(action input, char a);
	~Rooms();
};

#endif //__ROOMS_H__