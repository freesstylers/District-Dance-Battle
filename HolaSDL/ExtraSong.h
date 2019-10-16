#pragma once
#include "TextObject.h"
#include "EmptyObject.h"

class GameManager;

class ExtraSong :
	public EmptyObject
{
public:
	ExtraSong(GameManager* game, Vector2D pos, int width, int height, int texture, string title_, string artist_, int diff_, int num);
	~ExtraSong();
	virtual void render(bool time);
protected:
	TextObject* title;
	TextObject* artist;
	TextObject* diff;
};

