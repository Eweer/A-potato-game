#include "World.h"
#include "MemLeaks.h"

int main() {
	ReportMemoryLeaks();
	World* map = new World;
	map->CreateWorld();
	while (map->CheckInput());
	return 0;
}

