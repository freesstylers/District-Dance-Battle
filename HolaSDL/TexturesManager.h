#pragma once

#include "Font.h"
#include "Texture.h"
#include <string>

using namespace std;

/*
 *
 */

struct Animation {
	Texture* texture_;
	int frameWidth;
	int frameHeight;
	int columns;
	int rows;
	int totalFrames;

	int currentFrame = 0;
};


class TexturesManager {
public:
	TexturesManager();
	virtual ~TexturesManager();

	// supposed to be called before start using the object
	virtual bool init() = 0;

	virtual Animation* getAnimation(int tag) = 0;
	virtual bool loadFromImg(int tag, SDL_Renderer* renderer, string fileName, int width, int height, int columns, int rows, int totalFrames) = 0;
	virtual bool loadFromText(int tag, SDL_Renderer* renderer, string texto, Font& font, SDL_Color color = { 0, 0, 0, 255 }) = 0;
};
