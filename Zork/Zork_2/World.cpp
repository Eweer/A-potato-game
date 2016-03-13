#include "World.h"

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

	player_moved = false;

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
	player->CreatePlayer();
}

void World::Move(action a) {
	switch (player->get_loc()) {
	case CHURCH_BACKYARD:
		if (church_backyard->CheckExit(a)) {
			if (church_backyard->CheckDoorMove(a) == OPEN_DOOR || church_backyard->CheckDoorMove(a) == DONT_EXIST) {
				player->change_loc(church_backyard->move(a));
				player_moved = true;
			}
			else if (church_backyard->CheckDoorMove(a) == CLOSE_DOOR)
				printf("There is a closed door in front of you.\n");
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case CHURCH:
		if (church->CheckExit(a)) {
			if (church->CheckDoorMove(a) == OPEN_DOOR || church->CheckDoorMove(a) == DONT_EXIST) {
				player->change_loc(church->move(a));
				player_moved = true;
			}
			else if (church->CheckDoorMove(a) == CLOSE_DOOR)
				printf("There is a closed door in front of you.\n");
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case FOUNTAIN:
		if (fountain->CheckExit(a)) {
			player->change_loc(fountain->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case PARK:
		if (park->CheckExit(a)) {
			player->change_loc(park->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case BUILDING:
		if (building->CheckExit(a)) {
			player->change_loc(building->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case SCHOOL:
		if (school->CheckExit(a)) {
			player->change_loc(school->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case TOWN_HALL:
		if (town_hall->CheckExit(a)) {
			player->change_loc(town_hall->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	case COFFEE:
		if (coffee->CheckExit(a)) {
			player->change_loc(coffee->move(a));
			player_moved = true;
		}
		else
			printf("You hit a wall, this is not the way.\n");
		break;
	}
}

void World::OpenClose(action a) {
	printf("What door do you want to open? (n/s/e/w) \n");
	char dir;
	scanf_s("%c", &dir, 1);
	switch (a) {
	case OPEN:
		switch (player->get_loc()) {
		case CHURCH_BACKYARD:
			if (church_backyard->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (church_backyard->CheckDoor(dir) == CLOSE_DOOR) {
				church_backyard->ChangeDoorOpenClose(a, dir);
				church->ChangeDoorOpenClose(a, 'n');
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case CHURCH:
			if (church->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (church->CheckDoor(dir) == CLOSE_DOOR) {
				church->ChangeDoorOpenClose(a, dir);
				church_backyard->ChangeDoorOpenClose(a, 's');
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case FOUNTAIN:
			if (fountain->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (fountain->CheckDoor(dir) == CLOSE_DOOR) {
				fountain->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case COFFEE: 
			if (coffee->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (coffee->CheckDoor(dir) == CLOSE_DOOR) {
				coffee->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case TOWN_HALL:
			if (school->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (school->CheckDoor(dir) == CLOSE_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case PARK:
			if (school->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (school->CheckDoor(dir) == CLOSE_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case SCHOOL:
			if (school->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (school->CheckDoor(dir) == CLOSE_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case BUILDING:
			if (school->CheckDoor(dir) == OPEN_DOOR)
				printf("The door is already opened");
			else if (school->CheckDoor(dir) == CLOSE_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You openned the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		}
		break;
	case CLOSE:
		switch (player->get_loc()) {
		case CHURCH_BACKYARD:
			if (church_backyard->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (church_backyard->CheckDoor(dir) == OPEN_DOOR) {
				church_backyard->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case CHURCH:
			if (church->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (church->CheckDoor(dir) == OPEN_DOOR) {
				church->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case FOUNTAIN:
			if (fountain->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (fountain->CheckDoor(dir) == OPEN_DOOR) {
				fountain->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case COFFEE:
			if (coffee->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (coffee->CheckDoor(dir) == OPEN_DOOR) {
				coffee->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case TOWN_HALL:
			if (school->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (school->CheckDoor(dir) == OPEN_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case PARK:
			if (school->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (school->CheckDoor(dir) == OPEN_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case SCHOOL:
			if (school->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (school->CheckDoor(dir) == OPEN_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		case BUILDING:
			if (school->CheckDoor(dir) == CLOSE_DOOR)
				printf("The door is already closed");
			else if (school->CheckDoor(dir) == OPEN_DOOR) {
				school->ChangeDoorOpenClose(a, dir);
				printf("You closed the door.\n");
			}
			else
				printf("There are no doors here.\n");
			break;
		}
		break;
	}
	getchar();
	player_moved = false;
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
	else if (input == "open door" || input == "open gate")
		return OPEN;
	else if (input == "close door" || input == "close gate")
		return CLOSE;
	else if (input == "x")
		return EXIT_GAME;
	return NOPE;
}

bool World::CheckInput() {
	std::string input;
	std::getline(std::cin, input);
	action a = TransformInput(input);
	if (a == EXIT_GAME)
		return false; //Game will end
	else if (a == NOPE)
		printf("I don't understand what you are saying. Please, enter a valid expresion\n");
	else if (a >= NORTH && a <= WEST)
		Move(a);
	else if (a == OPEN || a == CLOSE)
		OpenClose(a);
	Output();
	return true;
}

void World::Output() {
	if (player_moved) {
		switch (player->get_loc()) {
		case CHURCH:
			church->OutputDescription();
			break;
		case CHURCH_BACKYARD:
			church_backyard->OutputDescription();
			break;
		case FOUNTAIN:
			fountain->OutputDescription();
			break;
		case COFFEE:
			coffee->OutputDescription();
			break;
		case TOWN_HALL:
			town_hall->OutputDescription();
			break;
		case PARK:
			park->OutputDescription();
			break;
		case SCHOOL:
			school->OutputDescription();
			break;
		case BUILDING:
			building->OutputDescription();
			break;
		}
	}
	player_moved = false;
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
