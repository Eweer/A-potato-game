#include "Players.h"

Players::Players() {
	loc = NOTHING;
}

void Players::CreatePlayer() {
	loc = FOUNTAIN;
}

location Players::get_loc() const{
	return loc;
}

void Players::change_loc(location place) {
	loc = place;
}