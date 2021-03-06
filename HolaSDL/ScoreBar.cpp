#include "ScoreBar.h"

ScoreBar::ScoreBar(SDLGame* game, double width, double height, Vector2D pos, double maxScore, double maxY) : 
	GameObject(game), maxScore_(maxScore), maxHeight_(400), currentHeight(height)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	animation = *getGame()->getServiceLocator()->getTextures()->getAnimation(Resources::YellowBar);

	originalY_ = pos.getY();
	//maxHeight_ = originalY_ - maxY;	//the maxY only represents the maximum y position, not the actual height (distance from the original y pos to the maximum y pos)

	stars = new EmptyObject(game, Vector2D(pos.getX() - 1, pos.getY() - maxHeight_), width + 2, maxHeight_ + 2, Resources::StarBar);
	particleEffect = new ParticleEngine(60, pos, game);
}

bool ScoreBar::handleInput(Uint32 time, const SDL_Event& event) {
	return false;
}

//Updates the score bar respect to a maximun height
void ScoreBar::updateBar(double punt)
{
	currentHeight = (punt * maxHeight_) / maxScore_;

	setHeight(currentHeight);
	position_.setY(originalY_ - currentHeight);
	if (currentHeight >= ((currentStar + 1)*maxHeight_ / 5)-30)
	{
		currentStar++;
		stars->animation.currentFrame = currentStar;
		particleEffect->setPosition(Vector2D(this->getPosition().getX() + width_ / 2, stars->getPosition().getY() + (5 - (currentStar))*(maxHeight_ / 5)));
		particleEffect->generate(60);
		game_->getServiceLocator()->getAudios()->playChannel(Resources::StarSound, 0, 1);
	}
}

void ScoreBar::render(Uint32 time, bool beatSync)
{
	if (active_) {
		if ((!isAnimationSyncedToMusic) || (isAnimationSyncedToMusic && beatSync)) {	//animations update only when a certain time has passed OR when the "beatSync" signal is true
			animation.currentFrame = animation.currentFrame + 1;

			if (animation.currentFrame == animation.totalFrames) {
				animation.currentFrame = 0;

				if (queuedAnimations.size() > 0) {
					changeAnimation(queuedAnimations.front());
				}
			}

			lastRender = time;
		}

		animation.texture_->render(getRect(), &getFrameRect(), alpha_);
	}
	stars->render(time, false);
	particleEffect->render(time, false);
}

ScoreBar::~ScoreBar()
{
	delete particleEffect;
	delete stars;
}