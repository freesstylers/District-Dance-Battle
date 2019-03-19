#include "EmptyObject.h"


EmptyObject::EmptyObject(SDLGame* game, Vector2D pos, int width, int height, int texture): GameObject(game)
{
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(texture);
	setWidth(width);
	setHeight(height);
}

void EmptyObject::render(Uint32 time, bool beatSync)
{
	if (active_) {
		animation.texture_->render(getRect(), getFrameRect());
		animation.currentFrame = animation.currentFrame + 1;
		if (animation.currentFrame == animation.totalFrames) {
			animation.currentFrame = 0;

			if (queuedAnimations.size() > 0) {
				changeAnimation(queuedAnimations.front());
			}
		}

		lastRender = time;
	}
}
