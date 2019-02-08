#pragma once
#include "GameObject.h"

/*
 *
 */
class Bullet : public GameObject {
public:
	Bullet();
	Bullet(SDLGame* game);
	virtual ~Bullet();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

