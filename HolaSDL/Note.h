#pragma once
#include "GameObject.h"
#include "checkML.h"

//Nothing really to say here, just Notes class

class Note: public GameObject
{
protected:
	SDL_GameControllerButton key;
	
public:
	Note(SDL_GameControllerButton key, SDLGame* game, double width, double height, Vector2D pos, Vector2D vel,bool isXbox);
	virtual ~Note();
	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; };
	virtual void update(Uint32 time);
	SDL_GameControllerButton getKey() { return key; }; //Button/Arrow linked to the Note

	void changeController(bool isXbox);
};

