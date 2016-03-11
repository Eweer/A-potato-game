#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "Globals.h"

class Players
{
private:
	location loc;

public:
	Players();
	location get_loc() const;
	void change_loc(location place);
};

#endif //__PLAYERS_H__