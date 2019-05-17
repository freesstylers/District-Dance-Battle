#include "ParticleEngine.h"



ParticleEngine::ParticleEngine(int maxpart, Vector2D pos, SDLGame* gm) : GameObject(gm), maxParticles(maxpart)
{
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
}
ParticleEngine::~ParticleEngine()
{
	for (int i = 0;i < particles.size();i++)
		delete particles[i];
}
void ParticleEngine::generate(int num)
{
	for (int i = 0;i < num;i++)  //create maxparticle number of particles with random values both for position, velocity, life, color
		particles.push_back(new Particle(Vector2D(position_.getX() + rand() % 6 - 3, position_.getY() + rand() % 6 - 3), Vector2D(rand() % 10 + (float)rand() / (float)RAND_MAX - 5, rand() % 10 + (float)rand() / (float)RAND_MAX - 5), 500 + rand() % 2000, 16, 16, game_));
}
void ParticleEngine::render(Uint32 time, bool beatSync)
{
	for (int i = 0;i < particles.size();i++)
	{
		if (particles[i] != nullptr)
			particles[i]->render(time, false);
	}
}
void ParticleEngine::update(Uint32 time)
{
	for (int i = 0; i < particles.size(); i++)
	{
		if (!particles[i]->isDead())
			particles[i]->update(time);
		else
		{
			delete particles[i];
			particles[i] = nullptr;
			particles.erase(particles.begin() + i);
		}
	}
}
