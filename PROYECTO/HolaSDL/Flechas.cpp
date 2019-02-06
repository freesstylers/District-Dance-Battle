#include "Flechas.h"



Flechas::Flechas()
{
}

Flechas::Flechas(Vector2D pos, Texture* texture, int key, int h, int w): pos(pos), texture(texture), key(key), h(h), w(w){}

void Flechas::update()
{
	Vector2D newpos(pos.CompX() - 5, pos.CompY());
	pos = newpos;
}
SDL_Rect Flechas::getRect()
{
	SDL_Rect rect;
	rect.h = h;
	rect.w = w;
	rect.x = pos.CompX();
	rect.y = pos.CompY();
	return rect;
}
void Flechas::render()
{
	texture->render(getRect());
}
void Flechas::handleEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == 115)
		{
			delete this;
		}
	}
}
Vector2D Flechas::getPos()
{
	return pos;
}
Flechas::~Flechas()
{
}
