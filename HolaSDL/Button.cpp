#include "Button.h"


Button::Button()
{
}

Button::Button(GameManager* game, double width, double height, Vector2D pos, Callback* callback):
	GameObject(game),  callback(callback), gameManager_(game)
{
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::YButton);

	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
}

bool Button::handleInput(Uint32 time, const SDL_Event& event) {
	if (active_ && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		return checkButton(event.button.x, event.button.y);
	}
	return false;
}


bool Button::checkButton(int x, int y) {
	SDL_Rect auxRect = getRect();

	//If you click inside of the button, the callback function is called
	if ((x > auxRect.x) && (x < auxRect.x + auxRect.w) && (y > auxRect.y) && (y < auxRect.y + auxRect.h)) {
		callback(gameManager_);
		return true;
	}
	return false;
}

void Button::callCallback()
{
	callback(gameManager_);
}

void Button::update(Uint32 time)
{
	

}

Button::~Button()
{

}
