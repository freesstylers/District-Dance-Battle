#include "Button.h"

Button::Button(SDLGame* game, double width, double height, Vector2D pos, Callback* callback) :
	GameObject(game), texture(texture), callback(callback)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(Vector2D(0, 0));
}

void Button::handleEvent(Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		checkButton(event.button.x, event.button.y);
	}
}

void Button::checkButton(int x, int y) {
	SDL_Rect auxRect = getRect();

	//Si pulsa dentro del rectángulo
	if ((x > auxRect.x) && (x < auxRect.x + auxRect.w) && (y > auxRect.y) && (y < auxRect.y + auxRect.h)) {
		callback(game_);	//llama a la función callback
	}
}

void Button::render() {
	texture->render(getRect());
}