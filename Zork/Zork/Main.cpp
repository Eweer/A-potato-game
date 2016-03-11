#include "World.h"
#include "MemLeaks.h"

int main() {
	ReportMemoryLeaks();
	World* map = new World;
	while (map->CheckInput()) {
		//player->change_loc(location);
	}

}