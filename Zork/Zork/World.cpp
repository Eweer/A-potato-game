#include "World.h"
#include <iostream>

World::World() {
	church = new Rooms;
	fountain = new Rooms;
	coffee = new Rooms;
	town_hall = new Rooms;
	park = new Rooms;
	school = new Rooms;
	building = new Rooms;
	church_backyard = new Rooms;
	
	player = new Players;

}

void World::CreateWorld() {
	//Rooms
	church->CreateRoom(CHURCH);
	fountain->CreateRoom(FOUNTAIN);
	coffee->CreateRoom(COFFEE);
	town_hall->CreateRoom(TOWN_HALL);
	park->CreateRoom(PARK);
	school->CreateRoom(SCHOOL);
	building->CreateRoom(BUILDING);
	church_backyard->CreateRoom(CHURCH_BACKYARD);

	//Player
	player->change_loc(FOUNTAIN);
}

void World::move(action a) {
	switch (player->get_loc()) {
	case CHURCH_BACKYARD:
		player->change_loc(church_backyard->move(a));
		break;
	case CHURCH:
		player->change_loc(church->move(a));
		break;
	case FOUNTAIN:
		player->change_loc(fountain->move(a));
		break;
	case PARK:
		player->change_loc(fountain->move(a));
		break;
	case BUILDING:
		player->change_loc(building->move(a));
		break;
	case SCHOOL:
		player->change_loc(school->move(a));
		break;
	case TOWN_HALL:
		player->change_loc(town_hall->move(a));
		break;
	case COFFEE:
		player->change_loc(coffee->move(a));
		break;
	}
}

action World::TransformInput(const std::string input) {
	if (input == "north" || input == "n")
		return NORTH;
	else if (input == "east" || input == "e")
		return EAST;
	else if (input == "south" || input == "s")
		return SOUTH;
	else if (input == "west" || input == "w")
		return WEST;
	else if (input == "open door" || "open gate")
		return OPEN;
	else if (input == "close door" || "close gate")
		return CLOSE;
	else if (input == "x")
		return EXIT_GAME;
	return NOPE;
}

bool World::CheckInput() {
	printf("Where do you want to go? (n/s/e/w) ");
	std::string input;
	std::getline(std::cin, input);
	action a = TransformInput(input);
	printf("%d", a);
	if (a == EXIT_GAME)
		return false; //Game will end
	else {
		move(a);
		return true;
	}
	Output();
	getchar();
}

void World::Output() {
	switch (player->get_loc()) {
	case CHURCH:
		printf("LOLAAAAAAAAILO");
		printf("%s", church->GetDescription().c_str());
		break;
	case CHURCH_BACKYARD:
		printf("%s", church_backyard->GetDescription().c_str());
		break;
	case FOUNTAIN:
		printf("%s", fountain->GetDescription().c_str());
		break;
	case COFFEE:
		printf("%s", coffee->GetDescription().c_str());
		break;
	case TOWN_HALL:
		printf("%s", town_hall->GetDescription().c_str());
		break;
	case PARK:
		printf("%s", park->GetDescription().c_str());
		break;
	case SCHOOL:
		printf("%s", school->GetDescription().c_str());
		break;
	case BUILDING:
		printf("%s", building->GetDescription().c_str());
		break;
	}
}

World::~World(){
	delete church;
	delete church_backyard;
	delete fountain;
	delete park;
	delete building;
	delete school;
	delete town_hall;
	delete coffee;
	
	delete player;
}
