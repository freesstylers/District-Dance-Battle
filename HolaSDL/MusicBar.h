#pragma once
#include "GameObject.h"
class MusicBar: public GameObject
{
protected:
	int longitudBarra;
private:
	Texture* texture;

public:
	MusicTimer();
	virtual ~MusicTimer();
	virtual bool handleInput(Uint32 time, const SDL_Event& event);

	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

