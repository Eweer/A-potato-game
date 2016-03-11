#include "Rooms.h"

Rooms::Rooms(){
	loc = NOTHING;
	description = "";
	exit = new Exits;
}

location Rooms::move(char a) {
	return exit->move_player(a);
}

Rooms::~Rooms() {
	delete exit;
}