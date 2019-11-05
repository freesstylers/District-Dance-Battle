#pragma once
#include "TextObject.h"
#include "EmptyObject.h"

class GameManager;

class ExtraSong :
	public EmptyObject
{
public:
	ExtraSong(GameManager* game, Vector2D pos, int width, int height, int texture, string title_, string artist_, int lvl);
	~ExtraSong();
	virtual void render(bool time);

	int getLevel() { return level; }

protected:
	TextObject* title = nullptr;
	TextObject* diff = nullptr;
	int level = 0;

};

