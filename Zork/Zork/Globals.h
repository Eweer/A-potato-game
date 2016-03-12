#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum location {
	CHURCH_BACKYARD = 0,
	CHURCH,
	FOUNTAIN,
	COFFEE,
	TOWN_HALL,
	PARK,
	SCHOOL,
	BUILDING,
	NOTHING
};

enum action {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	OPEN,
	CLOSE,
	NOPE,
	EXIT_GAME
};

#endif //_GLOBALS_H_