#include "Egg.h"

// we allow creating an egg without initializing anything. Should be
// initialized by calling init before it is used
Egg::Egg() :
		GameObject(nullptr), eggTexture_(nullptr) {
}

Egg::Egg(SDLGame* game) :
		GameObject(game) {
	width_ = eggTexture_->getWidth() * 0.1;
	height_ = eggTexture_->getHeight() * 0.1;
}

Egg::~Egg() {
}

void Egg::handleInput(Uint32 time, const SDL_Event& event) {
}

void Egg::update(Uint32 time) {
	if (!isActive()) // if not active do nothing
		return;

	// change velocity and position
	velocity_ = velocity_ + acceleration_;
	position_ = position_ + velocity_;

	// when going out of the screen deactivate it
	if (position_.getX() + width_ <= 0
			|| position_.getX() >= getGame()->getWindowWidth()
			|| position_.getY() + height_ <= 0
			|| position_.getY() >= getGame()->getWindowHeight()) {
		toggleActive();
	}
}

void Egg::render(Uint32 time) {
	if (!isActive()) // if not active do nothing
		return;

	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
			getHeight());

	if (eggTexture_ == nullptr)
		eggTexture_ = getGame()->getServiceLocator()->getTextures()->getTexture(
				Resources::FireEgg);

	// render the egg
	eggTexture_->render(dest);
}

