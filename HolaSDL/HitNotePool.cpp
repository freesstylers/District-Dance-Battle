#include "HitNotePool.h"



HitNotePool::HitNotePool(SDLGame* game, double width, double height) : GameObjectPool<HitNote, 30>(game)
{
	for (auto hit : getAllObjects()) {
		hit->setWidth(width);
		hit->setHeight(height);
	}
}


HitNotePool::~HitNotePool()
{
}

void HitNotePool::addHit(int animation, Vector2D pos)
{
	HitNote* h = getUnusedObject();

	pos.setX(pos.getX() - 10);
	pos.setY(pos.getY() - 10);

	h->forceAnimationChange(animation);
	h->setPosition(pos);
	h->setActive(true);
}
