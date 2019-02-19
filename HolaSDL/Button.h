#pragma once
#include "GameObject.h"


class Button : public GameObject {
private:
	typedef void Callback(SDLGame* game);
	int type;
	Texture* texture;

	Callback* callback;


public:

	Button(SDLGame* game, double width, double height, Vector2D pos, Callback* callback);
	void handleInput(Uint32 time, const SDL_Event& event);
	void render(Uint32 time);

	void checkButton(int x, int y);
};
