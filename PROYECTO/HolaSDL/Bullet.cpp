#include "Bullet.h"

Bullet::Bullet() {
}

Bullet::Bullet(SDLGame* game) {
}

Bullet::~Bullet() {
}

void Bullet::handleInput(Uint32 time, const SDL_Event& event) {
}

void Bullet::update(Uint32 time) {
	if (!isActive()) // if not active do nothing
		return;

	// change velocity and position
	position_ = position_ + velocity_;

	// when going out of the screen deactivate it
	if (position_.getX() + width_ <= 0
			|| position_.getX() >= getGame()->getWindowWidth()
			|| position_.getY() + height_ <= 0
			|| position_.getY() >= getGame()->getWindowHeight()) {
		toggleActive();
	}
}

void Bullet::render(Uint32 time) {
	if (!isActive()) // if not active do nothing
		return;

	Vector2D lineEndPoint = position_ + velocity_.normalize();
    SDL_SetRenderDrawColor( getGame()->getRenderer(), COLOR(0xFFFFFFFF) );
	SDL_RenderDrawLine(getGame()->getRenderer(), position_.getX(),
			position_.getY(), lineEndPoint.getX(), lineEndPoint.getY());
}
