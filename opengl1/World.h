#pragma once
#include "Entity.h"
#include "swarmz.h"

using namespace sw;
class World
{
	
	
public:

	
	std::vector<Boid> boids;
	Entity e[100];
	World(bool* draw);
	~World();
	void run();

	
};

