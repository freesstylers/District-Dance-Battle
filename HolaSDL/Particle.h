#pragma once
#include <stdint.h>
#include "GameObject.h"
#include "checkML.h"

//Particles, to make the combo animation better, base of Particle Engine

class Particle : public GameObject
{
private:
	Uint32 endTime; //death time
	int life_;
public:
	Particle(Vector2D pos, Vector2D vel, int life,int h, int w, SDLGame* Game);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; }
	bool isDead();  //true if the particle dead else false
	~Particle() {};
};

