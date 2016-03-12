#ifndef __WORLD_H__
#define __WORLD_H__

#include "Rooms.h"
#include "Players.h"
#include <stdio.h>
#include <string>

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

	void move(action a);
	action TransformInput(const std::string input);

public:
	World();
	void CreateWorld();
	bool CheckInput();
	void Output();
	~World();
};

#endif //__WORLD_H__