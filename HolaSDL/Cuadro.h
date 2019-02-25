#pragma once
#include "GameObject.h"
class Cuadro : public GameObject
{
private:
	Texture* texture;

	int frames_;
	int currFrame_;
	int cols_;
	int rows_;
	int frameWidth_;
	int frameHeight_;

	Uint32 lastTimeUpdated_;  // last time we update a frame
	Uint32 freq_; // the frequency of updating frames
public:
	Cuadro();
	Cuadro(SDLGame* game, double width, double height, Vector2D pos);
	~Cuadro();
	virtual void handleInput(Uint32 time, const SDL_Event& event) {} //Puede que no lo necesitemos si se lleva las pulsaciones desde pulsador
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
};

