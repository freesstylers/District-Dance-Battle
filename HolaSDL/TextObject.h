#pragma once
#include "GameObject.h"
class TextObject :
	public GameObject
{
protected:
	Texture* text;
	Font* textFont;

public:
	TextObject(SDLGame* manager, Font* font, Vector2D pos);
	~TextObject();

	virtual bool handleInput(Uint32 time, const SDL_Event& event) { return false; };
	virtual void update(Uint32 time);
	virtual void render(Uint32 time, bool beatSync = false);

	void setText(string txt);
};

