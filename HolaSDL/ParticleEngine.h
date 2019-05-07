#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Particle.h"
#include "GameObject.h"
#include "checkML.h"

class ParticleEngine : public GameObject
{
private:
	vector<Particle*> particles;
	int maxParticles;

public:
	ParticleEngine(int maxpart, Vector2D pos, SDLGame* game);
	virtual void update(Uint32 time);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; };
	virtual void render(Uint32 time, bool beatSync);
	void generate(int num);
	~ParticleEngine();
};

