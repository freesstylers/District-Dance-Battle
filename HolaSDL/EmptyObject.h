#pragma once
#include "GameObject.h"
class EmptyObject :
	public GameObject
{
public:
	EmptyObject(SDLGame* game, Vector2D pos,int textura,int width,int height);
	virtual ~EmptyObject();
};

