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

void World::move(const std::string b) {
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

int World::CheckInput() {
	printf("Where do you want to go? (n/s/e/w) ");
	std::string input;
	std::getline(std::cin, input);
	if (input == "x")
		return 0; //Game will end
	else
		move(a);

	getchar();
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
