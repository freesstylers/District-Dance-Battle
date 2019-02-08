#pragma once

#include "Vector2D.h"
#include "GameObject.h"

/*
 *
 */
class Collisions {
public:
	Collisions();
	virtual ~Collisions();

	static bool collides(GameObject* o1, GameObject* o2);

};
