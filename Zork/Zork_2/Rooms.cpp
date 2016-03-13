#include "Rooms.h"

Rooms::Rooms(){
	description = "";
	exit = new Exits;
}

void Rooms::CreateRoom(location loc) {
	switch (loc) {
	case CHURCH_BACKYARD:
		description = "OMG, you found a horrocrux\n";
		exit->create_exits(CHURCH_BACKYARD);
		break;
	case CHURCH:
		description = "You are in the church, you see a door behind Jesus. Wololooooooooo.\n";
		exit->create_exits(CHURCH);
		break;
	case FOUNTAIN:
		description = "You are on the fountain, there's a church on the east, a town hall on the north, a park on the west... So cliché\n";
		exit->create_exits(FOUNTAIN);
		break;
	case PARK:
		description = "What a beautiful park, but it's pretty useless\n";
		exit->create_exits(PARK);
		break;
	case BUILDING:
		description = "When I say: Wanna me to wash your back? I expect a yes or no, not a: Who are you and what are you doing in my house?\n";
		exit->create_exits(BUILDING);
		break;
	case SCHOOL:
		description = "You don't have childs... What are you doing in this school? GTFO\n";
		exit->create_exits(SCHOOL);
		break;
	case TOWN_HALL:
		description = "This town hall should be a jail, really.\n";
		exit->create_exits(TOWN_HALL);
		break;
	case COFFEE:
		description = "Coffee... what a blessing of god\n";
		exit->create_exits(COFFEE);
		break;
	}
}

location Rooms::move(action a) {
	return exit->move_player(a);
}

std::string Rooms::GetDescription() {
	return description;
}

void Rooms::OutputDescription() {
	printf("%s", description.c_str());
}

bool Rooms::CheckExit(action input) {
	return exit->check_direction(input);
}

doors Rooms::CheckDoor(char dir) {
	return exit->CheckDoor(dir);
}

doors Rooms::CheckDoorMove(action a) {
	return exit->CheckDoorMove(a);
}

void Rooms::ChangeDoorOpenClose(action input, char a) {
	exit->ChangeExitOpenClose(input, a);
}

Rooms::~Rooms() {
	delete exit;
}