#include "Players.h"

Players::Players() {
	loc = CHURCH_BACKYARD;
}

location Players::get_loc() const{
	return loc;
}

void Players::change_loc(location place) {
	loc = place;
}