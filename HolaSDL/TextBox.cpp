#include "TextBox.h"



TextBox::TextBox(SDLGame* game, double width, double height, Vector2D pos, int i) :
	GameObject(game)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));


	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(i);

	framesPerSecond = 1;

	//Cambiar current frame si no se renderiza bien
	animation.currentFrame = 0;
}

bool TextBox::handleInput(Uint32 time, const SDL_Event& event) {

	return false;
}
