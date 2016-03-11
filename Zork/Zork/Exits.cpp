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

bool Exits::check_direction(char input) {
	switch (input) {
	case 'n':
		return (north != NOTHING);
		break;
	case 'e':
		return (east != NOTHING);
		break;
	case 's':
		return (south != NOTHING);
		break;
	case 'w':
		return (west != NOTHING);
		break;
	}
}

location Exits::move_player(char input) {
	if (check_direction(input)) {
		switch (input) {
		case 'n':
			return north;
			break;
		case 'e':
			return east;
			break;
		case 's':
			return south;
			break;
		case 'w':
			return west;
			break;
		}
	}
}