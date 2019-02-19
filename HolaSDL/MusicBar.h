#pragma once
#include "GameObject.h"
class MusicBar: public GameObject
{
protected:
	int longitudBarra;
private:
	Texture* texture;

public:
	MusicBar();
	virtual ~MusicBar();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

