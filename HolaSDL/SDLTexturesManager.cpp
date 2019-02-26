#include "SDLTexturesManager.h"

SDLTexturesManager::SDLTexturesManager() : initialized_(false) {
}

SDLTexturesManager::~SDLTexturesManager() {

	if ( !initialized_ )
		return;

	// free all textures
	for (const auto &pair : animations_) {
		if (pair.second != nullptr) {
			delete pair.second->texture_;
			delete pair.second;
		}
	}

	IMG_Quit();

}

bool SDLTexturesManager::init() {
	if ( initialized_ )
		return false;

	// SDL Image
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

	initialized_ = true;

	return true;
}


bool SDLTexturesManager::loadFromImg(int tag, SDL_Renderer* renderer,
		string fileName, int width, int height, int columns, int rows, int totalFrames) {

	if ( !initialized_ )
		return false;

	Animation* animation = new Animation;
	animation->texture_ = new Texture(renderer, fileName);
	animation->frameWidth = width;
	animation->frameHeight = height;
	animation->columns = columns;
	animation->rows = rows;
	animation->totalFrames = totalFrames;

	if (animation->texture_->isReady()) {
		storeAnimation(tag, animation);
		return true;
	}

	// if we get here something went wrong
	return false;
}

bool SDLTexturesManager::loadFromText(int tag, SDL_Renderer* renderer,
		string text, Font& font, SDL_Color color) {

	if ( !initialized_ )
		return false;

	Animation* animation = new Animation;
	animation->texture_ = new Texture(renderer, text, font, color);
	animation->frameWidth = animation->texture_->getWidth();
	animation->frameHeight = animation->texture_->getHeight();
	animation->columns = 1;
	animation->rows = 1;
	animation->totalFrames = 1;

	if (animation->texture_->isReady()) {
		storeAnimation(tag, animation);
		return true;
	}

	// if we get here something went wrong
	return false;

}

void SDLTexturesManager::storeAnimation(int tag, Animation* animation) {
	Animation* curr = animations_[tag];
	if (curr != nullptr){
		delete curr->texture_;
		delete curr;
	}
	animations_[tag] = animation;
}

Animation* SDLTexturesManager::getAnimation(int tag) {
	return animations_[tag];
}
