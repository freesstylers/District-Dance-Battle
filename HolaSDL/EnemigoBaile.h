#pragma once
#include "GameObject.h"
class EnemigoBaile :
	public GameObject
{
public:
	EnemigoBaile();
	virtual ~EnemigoBaile();
	virtual bool handleInput(Uint32 time, const SDL_Event& event); 
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

