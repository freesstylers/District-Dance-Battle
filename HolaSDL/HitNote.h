#pragma once
#include "GameObject.h"
#include "checkML.h"

//A simple gamobject used to play an animation whenever a note is hit

class HitNote :
	public GameObject
{
public:
	HitNote() : GameObject() {};
	HitNote(SDLGame* game, double width, double height, Vector2D pos);

	void init();

	virtual ~HitNote();
	virtual void update(Uint32 time) {};
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; };
	virtual void render(Uint32 time, bool beatSync = false);
};

