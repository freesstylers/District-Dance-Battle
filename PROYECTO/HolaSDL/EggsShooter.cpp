#include "EggsShooter.h"

EggsShooter::EggsShooter(SDLGame* game) :
		GameObject(game) {
	for (int i = 0; i < MAX_EGGS; i++) {
		eggs_[i].setActive(false);
		eggs_[i].setGame(game);
	}
}

EggsShooter::~EggsShooter() {
}

void EggsShooter::handleInput(Uint32 time, const SDL_Event& event) {
	for (int i = 0; i < MAX_EGGS; i++)
		if (eggs_[i].isActive()) {
			eggs_[i].handleInput(time, event);
		}
}

void EggsShooter::update(Uint32 time) {
	for (int i = 0; i < MAX_EGGS; i++)
		if (eggs_[i].isActive()) {
			eggs_[i].update(time);
		}
}

void EggsShooter::render(Uint32 time) {
	for (int i = 0; i < MAX_EGGS; i++)
		if (eggs_[i].isActive()) {
			eggs_[i].render(time);
		}
}

void EggsShooter::addEgg(Vector2D pos, Vector2D vel, Vector2D acc) {
	Egg* e = getUnusedEgg();
	if (e != nullptr) {
		int h = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 5);
		e->setWidth(24+h*0.8);
		e->setHeight(30+h);
		e->setVelocity(vel);
		e->setAcceleration(acc);
		e->setPosition(pos);
		e->setActive(true);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);

	}

}

Egg* EggsShooter::getUnusedEgg() {
	for (int i = 0; i < MAX_EGGS; i++)
		if (!eggs_[i].isActive()) {
			return &eggs_[i];
		}

	return nullptr;
}
