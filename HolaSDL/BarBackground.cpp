#include "BarBackground.h"

BarBackground::BarBackground(SDLGame* game, double width, double height, Vector2D pos, double vel, int texture) : GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	vel_ = vel;
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(texture); //en esta clase sucede lo mismo que en Background (lo único que lo diferencia es su llamada a la textura), 
}																				       //la barra del fondo es simplemente un sprite que sigue a SongBar, crear clase para asignar solo texturas a objetos vacios(?)
bool BarBackground::handleInput(Uint32 time, const SDL_Event& event) {
	return true;
}

BarBackground::~BarBackground()
{
}
