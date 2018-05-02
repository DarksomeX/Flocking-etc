#include <World.h>
#include <iostream>       
#include <thread> 

float MAX = 400;
float VELOCITY = 1;

Swarm swarm(NULL);


void World::run(){

	float x, y, z;
	while (true) {
		swarm.Update(1);

		for (int i = 0; i < 100; i++) {
			x = boids[i].Position.X;
			y = boids[i].Position.Y;
			z = boids[i].Position.Z;


			if (x >= MAX || x <= -MAX) {
				if (x >= MAX)
				{
					boids[i].Position.X = -MAX;
				}
				else
				{
					boids[i].Position.X = MAX;
				}
			}
			if (y >= MAX || y <= -MAX) {
				if (y >= MAX)
				{
					boids[i].Position.Y = -MAX;
				}
				else
				{
					boids[i].Position.Y = MAX;
				}
			}
			if (z >= MAX || z <= -MAX) {
				if (z >= MAX)
				{
					boids[i].Position.Z = -MAX;
				}
				else
				{
					boids[i].Position.Z = MAX;
				}
					
			}
			boids[i].Position += boids[i].Velocity;
		}
	}

	
}


World::World(bool* d)
{
	srand(static_cast <unsigned> (time(0)));


	for (int i = 0; i < 100; i++)
	{
		float x = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));
		float y = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));
		float z = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));

		float dx = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));
		float dy = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));
		float dz = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));

		boids.push_back(Boid(Vec3(x, y, z), Vec3(dx, dy, dz)));
	}

	swarm = Swarm(&boids);
	swarm.PerceptionRadius = 50;
	swarm.SeparationWeight = 1;
	swarm.CohesionWeight = 0.1;
	swarm.AlignmentWeight = 100;
	swarm.MaxVelocity = 3;

	std::thread gameloop(&World::run, this);
	gameloop.detach();
	

}


World::~World()
{

}
