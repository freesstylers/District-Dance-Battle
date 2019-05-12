#pragma once
#include "GameObject.h"
#include "checkML.h"

//Efecto pseudopsicodélico para la pantalla

class EffectVaporwave :
	public GameObject
{

public:
	EffectVaporwave() {}
	EffectVaporwave(SDLGame* game, Vector2D pos, int width, int height, int textura);
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; };
	virtual void update(Uint32 time) {};
	virtual void render(Uint32 time, bool beatSync);
	virtual ~EffectVaporwave() {}
};

