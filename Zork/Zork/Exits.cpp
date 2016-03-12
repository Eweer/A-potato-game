#include "Exits.h"
#include "Globals.h"

Exits::Exits() {
	north = NOTHING;
	south = NOTHING;
	east = NOTHING;
	west = NOTHING;
}

void Exits::create_exits(location place) {
	switch (place) {
	case CHURCH_BACKYARD:
		south = CHURCH_BACKYARD;
		break;
	case CHURCH:
		north = CHURCH_BACKYARD;
		south = FOUNTAIN;
		break;
	case FOUNTAIN:
		north = CHURCH;
		west = TOWN_HALL;
		south = PARK;
		east = COFFEE;
		break;
	case PARK:
		north = FOUNTAIN;
		west = SCHOOL;
		south = BUILDING;
		break;
	case BUILDING:
		north = PARK;
		break;
	case SCHOOL:
		east = PARK;
		break;
	case TOWN_HALL:
		east = FOUNTAIN;
		break;
	case COFFEE:
		west = FOUNTAIN;
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

location Exits::move_player(action input) {
//	if (check_direction(input)) {
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
	//}
}