#ifndef __EXITS_H__
#define __EXITS_H__

#include "Globals.h"

class Exits
{

	location north, south, east, west;

	bool check_direction(char input);

public:
	Exits();
	void create_exits(location place);
	location move_player(char input);
};

#endif //__EXITS_H__