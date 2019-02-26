#pragma once

#include "TexturesManager.h"
#include <map>

/*
 *
 */


class SDLTexturesManager : public TexturesManager {
public:
	SDLTexturesManager();
	virtual ~SDLTexturesManager();

	// supposed to be called before start using the object
	virtual bool init();

	virtual Animation* getAnimation(int tag);
	bool loadFromImg(int tag, SDL_Renderer* renderer, string fileName, int width, int height, int columns, int rows, int totalFrames);
	bool loadFromText(int tag, SDL_Renderer* renderer, string text, Font& font, SDL_Color color);
private:
	void storeAnimation(int tag, Animation* animation);

	bool initialized_;
	map<int,Animation*> animations_;

};
