#ifndef __WORLD_H__
#define __WORLD_H__

#include "Rooms.h"
#include "Players.h"
#include <iostream>
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
	
	bool player_moved;

	void Move(action a);
	void OpenClose(action a);
	action TransformInput(const std::string input);

public:
	World();
	void CreateWorld();
	bool CheckInput();
	void Output();
	~World();
};

#endif //__WORLD_H__