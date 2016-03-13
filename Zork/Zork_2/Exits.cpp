#include "Exits.h"
#include "Globals.h"

Exits::Exits() {
	north = NOTHING;
	south = NOTHING;
	east = NOTHING;
	west = NOTHING;
	north_open = DONT_EXIST;
	south_open = DONT_EXIST;
	east_open = DONT_EXIST;
	west_open = DONT_EXIST;
}

void Exits::create_exits(location place) {
	switch (place) {
	case CHURCH_BACKYARD:
		south_open = CLOSE_DOOR;
		south = CHURCH;
		break;
	case CHURCH:
		north_open = CLOSE_DOOR;
		north = CHURCH_BACKYARD;
		south = FOUNTAIN;
		break;
	case FOUNTAIN:
		north = CHURCH;
		west = TOWN_HALL;
		south = PARK;
		east = COFFEE;
		break;
	case COFFEE:
		west = FOUNTAIN;
		break;
	case TOWN_HALL:
		east = FOUNTAIN;
		break;
	case PARK:
		north = FOUNTAIN;
		west = SCHOOL;
		south = BUILDING;
		break;
	case SCHOOL:
		east = PARK;
		break;
	case BUILDING:
		north = PARK;
		break;
	}
}

bool Exits::check_direction(action input) {
	switch (input) {
	case NORTH:
		return (north != NOTHING);
		break;
	case EAST:
		return (east != NOTHING);
		break;
	case SOUTH:
		return (south != NOTHING);
		break;
	case WEST:
		return (west != NOTHING);
		break;
	}
}

doors Exits::CheckDoor(char a) {
	switch (a) {
	case 'n':
		return north_open;
		break;
	case 's':
		return south_open;
		break;
	case 'e':
		return east_open;
		break;
	case 'w':
		return west_open;
		break;
	}
}

doors Exits::CheckDoorMove(action input) {
	switch (input) {
	case NORTH:
		return north_open;
		break;
	case SOUTH:
		return south_open;
		break;
	case EAST:
		return east_open;
		break;
	case WEST:
		return west_open;
		break;
	}
}

void Exits::ChangeExitOpenClose(action input, char a) {
	switch (input) {
	case OPEN:
		switch (a) {
		case 'n':
			north_open = OPEN_DOOR;
			break;
		case 'e':
			east_open = OPEN_DOOR;
			break;
		case 's':
			south_open = OPEN_DOOR;
			break;
		case 'w':
			west_open = OPEN_DOOR;
			break;
		}
		break;
	case CLOSE:
		switch (a) {
		case 'n':
			north_open = CLOSE_DOOR;
			break;
		case 'e':
			east_open = CLOSE_DOOR;
			break;
		case 's':
			south_open = CLOSE_DOOR;
			break;
		case 'w':
			west_open = CLOSE_DOOR;
		}
	}
}

location Exits::move_player(action input) {
	switch (input) {
	case NORTH:
		return north;
		break;
	case EAST:
		return east;
		break;
	case SOUTH:
		return south;
		break;
	case WEST:
		return west;
		break;
	default:
		return NOTHING;
	}
}