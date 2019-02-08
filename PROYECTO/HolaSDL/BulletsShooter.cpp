#include "BulletsShooter.h"


BulletsShooter::BulletsShooter(SDLGame* game) : GameObject(game) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets_[i].setActive(false);
		bullets_[i].setGame(game);
	}
}

BulletsShooter::~BulletsShooter() {
}


void BulletsShooter::handleInput(Uint32 time, const SDL_Event& event) {
	for (int i = 0; i < MAX_BULLETS; i++)
		if (bullets_[i].isActive()) {
			bullets_[i].handleInput(time, event);
		}
}

void BulletsShooter::update(Uint32 time) {
	for (int i = 0; i < MAX_BULLETS; i++)
		if (bullets_[i].isActive()) {
			bullets_[i].update(time);
		}
}

void BulletsShooter::render(Uint32 time) {
	for (int i = 0; i < MAX_BULLETS; i++)
		if (bullets_[i].isActive()) {
			bullets_[i].render(time);
		}
}

void BulletsShooter::addBullet(Vector2D pos, Vector2D vel) {
	Bullet* e = getUnusedBullet();
	if (e != nullptr) {
		e->setVelocity(vel);
		e->setPosition(pos);
		e->setActive(true);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0);
	}
}

Bullet* BulletsShooter::getUnusedBullet() {
	for (int i = 0; i < MAX_BULLETS; i++)
		if (!bullets_[i].isActive()) {
			return &bullets_[i];
		}

	return nullptr;
}
