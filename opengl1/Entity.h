#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	


class Entity
{
public:

	int xi = 1;
	int yi = 1;
	int zi = 1;
	

	glm::vec3 position;
	glm::vec3 velocity = glm::vec3(5.0f, 5.0f, 5.0f);

	Entity(float a, float b, float c, glm::vec3 v, Entity * ent);
	Entity();

	~Entity();

	void Move();
	float distance(glm::vec3 first, glm::vec3 second);
};

