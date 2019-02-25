#pragma once

#include "TexturesManager.h"
#include <map>

/*
 *
 */

struct Animation {
	Texture* texture_;
	int firstFrameX;
	int firstFrameY;
	int nFramesX;
	int nFramesY;
	int totalFrames;
	int currentFrame = 0;
	int spriteWidth;
	int spriteHeight;
};


class SDLTexturesManager : public TexturesManager {
public:
	SDLTexturesManager();
	virtual ~SDLTexturesManager();

	// supposed to be called before start using the object
	virtual bool init();

	virtual Texture* getTexture(int tag);
	bool loadFromImg(int tag, SDL_Renderer* renderer, string fileName);
	bool loadFromText(int tag, SDL_Renderer* renderer, string text, Font& font, SDL_Color color);
private:
	void storeTexture(int tag, Texture* texture);

	bool initialized_;
	map<int,Texture*> textures_;

};
