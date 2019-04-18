#include "HitNote.h"

HitNote::HitNote(SDLGame* game, double width, double height, Vector2D pos) : GameObject(game)
{

	init();
}

void HitNote::init()
{
	isAnimationSyncedToMusic = false;
	framesPerSecond = 6;
	active_ = false;
}

HitNote::~HitNote()
{
}

void HitNote::render(Uint32 time, bool beatSync)
{
	if (active_) {
		animation.texture_->render(getRect(), getFrameRect(), alpha_);

		if ((!isAnimationSyncedToMusic && time - lastRender >= 1000 / framesPerSecond) || (isAnimationSyncedToMusic && beatSync)) {	//animations update only when a certain time has passed OR when the "beatSync" signal is true
			animation.currentFrame = animation.currentFrame + 1;

			if (animation.currentFrame == animation.totalFrames) {
				animation.currentFrame = 0;
				setActive(false);
			}

			lastRender = time;
		}

	}
}