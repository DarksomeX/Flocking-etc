INDX( 	 �lhB           (   8   �       U 	}athe                            ��    6 oޕ������&������&������&����                      s c . u s e r _ i n j e c t e d . 1 . e t l 0               ��    6 oޕ������&������&������&����                      S C U S E R ~ 2 . E T L                     p Z     ��    6 oޕ������&������&������&����                      S C U S E R ~ 2 . E T L                     ��    6 oޕ������&������&������&����                      S C  S E R ~ 2 . E T L                     ��    6 �U����xW����xW����xW����                      S C U S E R ~ 3 . E T L                     ��    6 �U����xW����xW����xW����                      S C U S E R ~ 3 . E T L                     				{
					boids[i].Position.Y = MAX;
				}
			}
			if (z >= MAX || z <= -MAX) {
				//boids[i].Velocity.Z *= -1;
				if (z >= MAX)
				{
					boids[i].Position.Z = -MAX;
				}
				else
				{
					boids[i].Position.Z = MAX;
				}
		 
			boids[i].Position += boids[i].Velocity;
		}
		
		//*draw = true;
	}
}



World::World(bool* d)
{
	srand(static_cast <unsigned> (time(0)));


	for (int i = 0; i < 1000; i++)
	{
		float x = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));
		float y = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));
		float z = -399 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (399 - (-399))));

		flo  dx = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));
		float dy = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));
		float dz = -VELOCITY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (VELOCITY - (-VELOCITY))));

		boids.push_back(Boid(Vec3(x, y, z), Vec3(dx, dy, dz)));
	}

	swarm =  Swarm(&boids);
	swarm.PerceptionRadius = 50;
	swarm.SeparationWeight = 1;
	swarm.Co sionWeight = 0.1;
	swarm.AlignmentWeight = 100;
	swarm.MaxVelocity = 3;

	draw = d;
	for (int i = 0; i < 10; i++) {
		std::thread gameloop(&World::run, this, 100*i, 100*(i+1));
		gameloop.detach();
	}
	
}


World::~World()
{

}
