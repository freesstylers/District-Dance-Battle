#pragma once
#include "GameObject.h"


class Button : public GameObject {
private:
	typedef void Callback(SDLGame* game);
	int type;
	Texture* texture;

	Callback* callback;


public:

	Button();
	Button(SDLGame* game, double width, double height, Vector2D pos, Callback* callback);
	virtual bool handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
	virtual ~Button();

	void checkButton(int x, int y);
};
