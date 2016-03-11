#ifndef __WORLD_H__
#define __WORLD_H__

#include "Rooms.h"
#include "Players.h"

class World
{
private:
	Rooms* church;
	Rooms* fountain;
	Rooms* coffee;
	Rooms* town_hall;
	Rooms* park;
	Rooms* school;
	Rooms* building;
	Rooms* church_backyard;

	Players* player;

	void move(char a);

public:
	World();
	int CheckInput();
	~World();
};

#endif //__WORLD_H__