#include "Entity.h"
#include <iostream>
#include <cmath>

int MAX = 400;
Entity * entities;

Entity::Entity(float a, float b, float c, glm::vec3 v, Entity * ent)
{
	position = glm::vec3(a, b, c);
	velocity = v;
	entities = ent;
}

Entity::Entity()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}


Entity::~Entity()
{
	
}

void Entity::Move() 
{

	glm::vec3 average = glm::vec3(0, 0, 0);
	int count = 0;
	float x = 0;
	float y = 0;
	float z = 0;

	float nx = 0;
	float ny = 0;
	float nz = 0;

	for (int i = 0; i < 100; i++)
	{
		if (distance(position, entities[i].position) <= 50) 
		{
			x += position.x;
			y += position.y;
			z += position.z;

			nx = (position.x - entities[i].position.x)*-1;
			ny = (position.y - entities[i].position.y)*-1;
			nz = (position.z - entities[i].position.z)*-1;

			average += entities[i].velocity;
			count++;
		}
		
	}


	nx /= count;
	ny /= count;
	ny /= count;

	float CMx = x / count / 400;
	float CMy = y / count / 400;
	float CMz = z / count / 400;

	average /= count;
	average.x += CMx + nx;
	average.y += CMy + ny;
	average.z += CMz + nz;
	velocity = average;
	

	if (position.x >= MAX || position.x <= -MAX) {
		xi = -xi;
		//position.x *= -1;
	}
	if (position.y >= MAX || position.y <= -MAX) {
		yi = -yi;
		//position.y *= -1;
	}
	if (position.z >= MAX || position.z <= -MAX) {
		zi = -zi;
		//position.z *= -1;
	}

	position.x += velocity.x * xi;
	position.y += velocity.y * yi;
	position.z += velocity.z * zi;
}

float Entity::distance(glm::vec3 first, glm::vec3 second) 
{
	return sqrt( pow(first.x-second.x,2) + pow(first.y - second.y, 2) + pow(first.z - second.z, 2));
}
