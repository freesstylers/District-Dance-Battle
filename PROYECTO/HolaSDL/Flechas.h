#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
class Flechas
{
private:
	Vector2D pos;
	Texture* texture;
	int key;
	int h, w;
public:
	Flechas();
	Flechas(Vector2D pos, Texture* texture,int key, int h, int w);
	~Flechas();
	void update();
	void handleEvents(SDL_Event& event);
	void render();
	int getKey() { return key; };
	SDL_Rect getRect();
	Vector2D getPos();
};

