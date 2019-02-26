#include "Button.h"

Button::Button()
{
}

Button::Button(GameManager* game, double width, double height, Vector2D pos, Callback* callback) :
	GameObject(game),  callback(callback), gameManager_(game)
{
	setTexture(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BotonY));
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));

	animation.firstFrameX = 0;
	animation.firstFrameY = 0;
	animation.nFramesX = 1;
	animation.nFramesY = 1;
	animation.totalFrames = 1;
	animation.currentFrame = 1;
	animation.spriteHeight = height;
	animation.spriteWidth = width;
}

bool Button::handleInput(Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		checkButton(event.button.x, event.button.y);
	}
	return false;
}


void Button::checkButton(int x, int y) {
	SDL_Rect auxRect = getRect();

	//Si pulsa dentro del rect�ngulo
	if ((x > auxRect.x) && (x < auxRect.x + auxRect.w) && (y > auxRect.y) && (y < auxRect.y + auxRect.h)) {
		callback(gameManager_);	//llama a la funci�n callback
	}
}

//void Button::render(Uint32 time) {
//	texture->render(getRect());
//}

void Button::update(Uint32 time)
{

}

Button::~Button()
{
}
