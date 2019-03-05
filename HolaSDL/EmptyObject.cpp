#include "EmptyObject.h"


EmptyObject::EmptyObject(SDLGame* game, Vector2D pos, int textura, int width, int height): GameObject(game)
{
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(textura);
	setWidth(width);
	setHeight(height);
}

void EmptyObject::render(Uint32 time, bool beatSync)
{
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

EmptyObject::~EmptyObject()
{
}
