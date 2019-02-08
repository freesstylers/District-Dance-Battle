#pragma once

#include "GameObject.h"

/*
 *
 */
class Egg : public GameObject {
public:
	Egg();
	Egg(SDLGame* game);
	virtual ~Egg();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	Texture* eggTexture_;
};

