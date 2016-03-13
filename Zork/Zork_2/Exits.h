#ifndef __EXITS_H__
#define __EXITS_H__

#include "Globals.h"

class Exits
{

	location north, south, east, west;
	doors north_open, south_open, east_open, west_open;



public:
	Exits();	
	bool check_direction(action input);
	void create_exits(location place);
	doors CheckDoor(char a);
	doors CheckDoorMove(action input);
	void ChangeExitOpenClose(action input, char a);
	location move_player(action input);
};

#endif //__EXITS_H__