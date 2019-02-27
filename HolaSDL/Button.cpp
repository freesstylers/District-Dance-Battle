#include "Button.h"

Button::Button()
{
}

Button::Button(GameManager* game, double width, double height, Vector2D pos, Callback* callback) :
	GameObject(game),  callback(callback), gameManager_(game)
{
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::BotonY);

	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
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
