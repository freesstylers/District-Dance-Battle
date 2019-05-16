#pragma once
#include "GameObjectPool.h"
#include "HitNote.h"
#include "checkML.h"

//A simple pool of HitNote objects

class HitNotePool :
	public GameObjectPool<HitNote, 30>
{
public:
	HitNotePool(SDLGame* game, double width, double height);
	~HitNotePool();

	virtual void addHit(int animation, Vector2D pos);
};

