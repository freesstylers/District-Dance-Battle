#include "Bird.h"
#include "Resources.h"

Bird::Bird(SDLGame* game, EggsShooter* eggsShooter) :
		GameObject(game) {
	eggsShooter_ = eggsShooter;
	birdTexture_ = getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Bird);

	// the bird texture has 14 frames in 3 rows and 5 cols
	frames_ = 14;
	cols_ = 5;
	rows_ = 3;

	// the width/height of a frame
	frameWidth_ = birdTexture_->getWidth() / cols_;
	frameHeight_ = birdTexture_->getHeight() / rows_;

	// we start at frame 0
	currFrame_ = 0;

	// we update a frame every 100ms (change dynamically)
	lastTimeUpdated_ = 0;
	freq_ = 100;
}

Bird::~Bird() {
}

void Bird::handleInput(Uint32 time, const SDL_Event& event) {
	if ( event.type == SDL_KEYDOWN ) {
		switch ( event.key.keysym.sym ) {
		case SDLK_s:
			// if the length of the velocity vector is less than 3, and
			// make the bird's flapping faster
			if ( velocity_.magnitude() < 3) {
				velocity_ = velocity_*1.1;
				freq_ = freq_*0.9;
			}
			break;
		case SDLK_a:
			// decrease velocity and make the bird's flapping slower
			velocity_ = velocity_*0.9;
			freq_ = freq_*1.1;
			break;
		case SDLK_z:
			// throw an egg
			eggsShooter_->addEgg(Vector2D(position_.getX()+width_/2,position_.getY()+height_), velocity_.rotate(10), Vector2D(0,0.01));
			break;
		default:
			break;
		}
	}
}

void Bird::update(Uint32 time) {

	// we update the frame every 100ms
	if (time - lastTimeUpdated_ >= freq_) {
		currFrame_ = (currFrame_ + 1) % frames_;
		lastTimeUpdated_ = time;
	}

	// change the position
	position_ = position_ + velocity_;

	// when exiting the right it appear from the opposite side
	if (position_.getX() >= getGame()->getWindowWidth()) {
		position_.setX(1 - width_);
	} else if (position_.getX() + width_ <= 0) {
		position_.setX(getGame()->getWindowWidth());
	}


}

void Bird::render(Uint32 time) {

	// compute the frame coordinates
	int row = currFrame_ / cols_;
	int col = currFrame_ % cols_;

	// the excat position of the frame in th etexture
	SDL_Rect clip = { col * frameWidth_, row * frameHeight_, frameWidth_,
			frameHeight_ };

	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
			getHeight());

	// render the frame
	birdTexture_->render(dest, &clip);
}
